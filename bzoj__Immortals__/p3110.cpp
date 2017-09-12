#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 200000
typedef long long ll;
using namespace std;
int n, m, p, x, ans[N];
ll c[N], d[N];
char s[50000*26+100];
struct qlz{
	int type, l, r, x, n;
}l[N], b1[N], b2[N];
int read(){
	int p=0, q=1;
	while (s[x]<'0' || s[x]>'9')
		if (s[x++]=='-') q=-1;
	while (s[x]>='0' && s[x]<='9') p=p*10+s[x++]-'0';
	return p*q;
}
void update(int l, int r, int x){
	for (int i=l;i<=p;i+=i&(-i)) c[i]+=x, d[i]+=(l-1)*x;
	for (int i=r+1;i<=p;i+=i&(-i)) c[i]-=x, d[i]-=r*x;
}
ll sum(int x){
	ll p=0;
	for (int i=x;i;i-=i&(-i)) p+=c[i]*x-d[i];
	return p;
}
void solve(int le, int ri, int L, int R){
	if (le>ri) return;
	if (L==R){
		for (int i=le;i<=ri;i++)
			if (l[i].type) ans[l[i].n]=L;
		return;
	}
	int x=L+R>>1;
	int ct1=0, ct2=0;
	for (int i=le;i<=ri;i++)
		if (l[i].type){
			ll k=sum(l[i].r)-sum(l[i].l-1);
			if (k<l[i].x){
				l[i].x-=k;
				b1[++ct1]=l[i];
			}
			else
				b2[++ct2]=l[i];
		}
		else
			if (l[i].x<=x)
				b1[++ct1]=l[i];
			else
				b2[++ct2]=l[i],
				update(l[i].l,l[i].r,1);
	for (int i=1;i<=ct1;i++) l[le+i-1]=b1[i];
	for (int i=1;i<=ct2;i++) l[le+ct1+i-1]=b2[i];
	for (int i=le;i<=ri;i++)
		if (!l[i].type && l[i].x>x) update(l[i].l,l[i].r,-1);
	solve(le,le+ct1-1,L,x);
	solve(le+ct1,ri,x+1,R);
}
int main(){
	fread(s,1,50000*26,stdin);
	p=(n=read())*3;m=read();
	for (int i=1;i<=m;i++){
		l[i].type=read()-1;
		l[i].l=read();
		l[i].r=read();
		l[i].x=read()+(l[i].type?0:2*n);
		l[i].n=i;
	}
	solve(1,m,1,p);
	for (int i=1;i<=m;i++)
		if (ans[i])
			printf("%d\n", ans[i]-2*n);
	return 0;
}
