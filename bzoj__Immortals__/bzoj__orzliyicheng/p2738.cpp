#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 600
#define M 500000
using namespace std;
int n, m, x, cnt, ans[M], q[M], c[N][N];
char s[6000010];
struct qlz{
	int n, v, x, y, c, x1, x2, y1, y2;
}l[M], b1[M], b2[M];
int read(){
	int p=0;
	while (s[x]<'0' || s[x]>'9') x++;
	while (s[x]>='0' && s[x]<='9') p=p*10+s[x++]-'0';
	return p;
}
bool cmp(qlz a, qlz b){return a.c<b.c;}
void update(int x, int y, int z){
	for (int i=x;i<=n;i+=i&(-i))
		for (int j=y;j<=n;j+=j&(-j))
			c[i][j]+=z;
}
int sum(int x, int y){
	int p=0;
	for (int i=x;i;i-=i&(-i))
		for (int j=y;j;j-=j&(-j))
			p+=c[i][j];
	return p;
}
void solve(int le, int ri, int L, int R){
	if (le>ri) return;
	if (L==R){
		for (int i=le;i<=ri;i++)
			if (!l[i].v) ans[l[i].n]=L;
		return;
	}
	int mid=L+R>>1;
	int ct1=0, ct2=0;
	for (int i=le;i<=ri;i++)
		if (l[i].v){
			if (l[i].v<=mid)
				b1[++ct1]=l[i],
				update(l[i].x,l[i].y,1);
			else
				b2[++ct2]=l[i];
		}
		else{
			int k=sum(l[i].x2,l[i].y2)+sum(l[i].x1-1,l[i].y1-1)-sum(l[i].x1-1,l[i].y2)-sum(l[i].x2,l[i].y1-1);
			if (k>=l[i].c)
				b1[++ct1]=l[i];
			else
				l[i].c-=k,
				b2[++ct2]=l[i];
		}
	for (int i=1;i<=ct1;i++) l[le+i-1]=b1[i];
	for (int i=1;i<=ct2;i++) l[le+ct1+i-1]=b2[i];
	//memcpy(l+le,b1+1,sizeof(l[0])*ct1);
	//memcpy(l+le+ct1,b2+1,sizeof(l[0])*ct2);
	for (int i=le;i<=ri;i++)
		if (l[i].v && l[i].v<=mid) update(l[i].x,l[i].y,-1);
	solve(le,le+ct1-1,L,mid);
	solve(le+ct1,ri,mid+1,R);
}
int main(){
	fread(s,1,6000000,stdin);
	n=read();m=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			l[++cnt].c=read(),
			l[cnt].x=i,
			l[cnt].y=j;
	sort(l+1,l+1+cnt,cmp);
	for (int i=1;i<=cnt;i++) q[l[i].v=i]=l[i].c;
	for (int i=1;i<=m;i++)
		l[++cnt].x1=read(),
		l[cnt].y1=read(),
		l[cnt].x2=read(),
		l[cnt].y2=read(),
		l[cnt].c=read(),
		l[cnt].n=i;
	solve(1,cnt,1,n*n);
	for (int i=1;i<=m;i++) printf("%d\n", q[ans[i]]);
	return 0;
}
