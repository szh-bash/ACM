#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define N 800000
#define M 20000000
#define P 8388608
using namespace std;
int n, m, x, cnt, f[M], ls[M], rs[M], root[N];
char s[4000000];
int read(){
	int p=0;
	while (s[x]<'0' || s[x]>'9') x++;
	while (s[x]>='0' && s[x]<='9') p=p*10+s[x++]-'0';
	return p;
}
void add(int t, int p){
	int q=P, tt=root[t-1];
	root[t]=++cnt;
	t=cnt;
	while (q){
		if (q&p){
			rs[t]=++cnt;
			ls[t]=ls[tt];
			t=rs[t];
			tt=rs[tt];
			f[t]=f[tt]+1;
		}
		else{
			ls[t]=++cnt;
			rs[t]=rs[tt];
			t=ls[t];
			tt=ls[tt];
			f[t]=f[tt]+1;
		}
		q>>=1;
	}
}
void solve(int l, int r, int x){
	int q=P, tl=root[l-1], tr=root[r], ans=0;
	while (q){
		if (q&x)
			if (f[ls[tr]]-f[ls[tl]])
				ans+=q,
				tl=ls[tl],
				tr=ls[tr];
			else
				tl=rs[tl],
				tr=rs[tr];
		else
			if (f[rs[tr]]-f[rs[tl]])
				ans+=q,
				tl=rs[tl],
				tr=rs[tr];
			else
				tl=ls[tl],
				tr=ls[tr];
		q>>=1;
	}
	printf("%d\n", ans);
}
int main(){
	gets(s);
	n=read()+1;m=read();
	int p=0;
	add(1,p);
	gets(s);x=0;
	for (int i=2;i<=n;i++) add(i,p^=read());
	for (int i=1;i<=m;i++){
		gets(s);x=0;
		if (s[0]=='A') add(++n,p^=read());
		if (s[0]=='Q'){
			int l=read(), r=read(), x=read()^p;
			solve(l,r,x);
		}
	}
	return 0;
}
