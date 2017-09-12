#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 100000
#define M 2500000
using namespace std;
int n, m, T, cnt, cnt_tree, LSH, a[N], trans[N], lsh[N], b1[N], b2[N], f[M], ls[M], rs[M], root[N];
char s[5];
map<int,int> mp;
struct qlz{
	int x, y, v, k;
}l[N];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void add(int x, int v ,int k){
	l[++cnt].x=x;l[cnt].v=v;l[cnt].k=k;
}
void update(int x, int v, int k){
	int ct=0, l=1, r=T;
	for (int i=x;i<=n;i+=i&(-i)){
		if (!root[i]) root[i]=++cnt_tree;
		f[b1[++ct]=root[i]]+=k;
	}
	while (l<r){
		int mid=l+r>>1;
		if (v>mid){
			for (int i=1;i<=ct;i++){
				if (!rs[b1[i]]) rs[b1[i]]=++cnt_tree;
				f[b1[i]=rs[b1[i]]]+=k;
			}
			l=mid+1;
		}
		else{
			for (int i=1;i<=ct;i++){
				if (!ls[b1[i]]) ls[b1[i]]=++cnt_tree;
				f[b1[i]=ls[b1[i]]]+=k;
			}
			r=mid;
		}
	}
}
void solve(int x, int y, int k){
	int ct1=0, ct2=0, l=1, r=T;
	for (int i=y;i;i-=i&(-i)) b1[++ct1]=root[i];
	for (int i=x-1;i;i-=i&(-i)) b2[++ct2]=root[i];
	while (l<r){
		int mid=l+r>>1, p=0;
		for (int i=1;i<=ct1;i++) p+=f[ls[b1[i]]];
		for (int i=1;i<=ct2;i++) p-=f[ls[b2[i]]];
		if (p>=k){
			for (int i=1;i<=ct1;i++) b1[i]=ls[b1[i]];
			for (int i=1;i<=ct2;i++) b2[i]=ls[b2[i]];
			r=mid;
		}
		else{
			for (int i=1;i<=ct1;i++) b1[i]=rs[b1[i]];
			for (int i=1;i<=ct2;i++) b2[i]=rs[b2[i]];
			k-=p;
			l=mid+1;
		}
	}
	printf("%d\n", trans[r]);
}
int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) add(i,lsh[++LSH]=a[i]=read(),1);
	for (int i=1;i<=m;i++){
		scanf("%s", s);
		if (s[0]=='Q'){
			l[++cnt].x=read();
			l[cnt].y=read();
			l[cnt].k=read();
		}
		else{
			int u=read(), v=read();
			if (a[u]==v) continue;
			add(u,a[u],-1);
			add(u,a[u]=v,1);
			lsh[++LSH]=v;
		}
	}
	sort(lsh+1,lsh+1+LSH);
	trans[mp[0]=++T]=0;
	for (int i=1;i<=LSH;i++)
		if (lsh[i]!=lsh[i-1])
			trans[mp[lsh[i]]=++T]=lsh[i];
	for (int i=1;i<=cnt;i++)
		if (l[i].y)
			solve(l[i].x,l[i].y,l[i].k);
		else
			update(l[i].x,mp[l[i].v],l[i].k);
	return 0;
}
