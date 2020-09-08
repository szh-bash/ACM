#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
ll readll(){
    ll p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
#define N 100005
#define M 1000000
int n, m, mv, le, ri, pos, f[M], a[N], b[N], c[N], g[N], l[N], flag[N], mod[N];
void build(int t, int l, int r){
	if (l==r){
		f[t]=1;
		return;
	}
	int mid=l+r>>1;
	build(t<<1, l, mid);
	build((t<<1)+1, mid+1, r);
	f[t]=f[t<<1]+f[(t<<1)+1];
}
void upd(int t, int l, int r){
	if (l==r){
		f[t]=0;
		return;
	}
	int mid=l+r>>1;
	if (pos<=mid) upd(t<<1, l, mid);
	else upd((t<<1)+1,mid+1,r);
	f[t]=f[t<<1]+f[(t<<1)+1];
}
int get(int t, int l, int r){
	if (le<=l && r<=ri) return f[t];
	int mid=l+r>>1;
	int sum1=0, sum2=0;
	if (le<=mid) sum1=get(t<<1,l,mid);
	if (ri>mid) sum2=get((t<<1)+1,mid+1,r);
	return sum1+sum2;
}
int find(int t, int l, int r){
	if (l==r) return l;
	int mid=l+r>>1;
	if (f[t<<1]<mv){
		mv-=f[t<<1];
		return find((t<<1)+1,mid+1,r);
	}
	return find(t<<1,l,mid);
}
void trans(int k, int x){
	build(1,1,n);
	for (int i=1;i<=n;i++) flag[i]=0, g[a[i]]=i, mod[i]=(x-1)%i+1;
	int ct=0;
	pos=1;
	for (int i=1, j=1;i<=n;i++){
		mv=(k-1)%(n-i+1)+1;
		le=pos, ri=n;
		int rp=get(1,1,n);
		if (rp<mv) mv-=rp;
		else mv+=(n-i+1-rp);	
		pos = find(1,1,n);
		upd(1,1,n);
		c[++ct]=a[pos];
	}
	for (int i=1;i<=n;i++)
		if (!flag[i]){
			int cnt=0;
			l[++cnt]=i;
			flag[i]=1;
			int j=g[c[i]];
			while (!flag[j]){
				flag[j]=1;
				l[++cnt]=j;
				j=g[c[j]];
			}
			int p=mod[cnt];
			for (int j=1;j<=cnt;j++){
				int tg=j+p;
				if (tg>cnt) tg-=cnt;
				b[l[j]]=a[l[tg]];
			}
		}
	for (int i=1;i<=n;i++) a[i]=b[i];
}
int main(){
	n=read(), m=read();
	for (int i=1;i<=n;i++) a[i]=i;
	for (int i=1;i<=m;i++){
		int k=read(), x=read();
		trans(k, x);
	}
	for (int i=1;i<=n;i++) printf("%d%s", a[i], (i==n?"\n":" "));
    return 0;
}
