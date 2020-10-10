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
#define mo 1000000007
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
#define N 2505
#define M N*N
int n, cnt, root[N], q[M];
int f[M], ls[M], rs[M];
ll sz[M];
char s[N];
void pushup(int t){
	f[t]=f[ls[t]]+f[rs[t]];
	sz[t]=sz[ls[t]]+sz[rs[t]];
	if (f[t]>=mo) f[t]-=mo;
}
void build(int &t, int l, int r){
	if (!t) t=++cnt;
	if (l==r){
		f[t]=s[l];
		sz[t]=1;
		return;
	}
	int mid=l+r>>1;
	build(ls[t],l,mid);
	build(rs[t],mid+1,r);
	pushup(t);
}
int main(){
	n=read();
	scanf("%s", s+1);
	build(root[0],1,strlen(s+1));
	for (int i=1;i<n;i++){
		char op[5];
		scanf("%s", op);
		if (op[0]=='S'){
			int x=read();
			ll lo=readll()+1, hi=readll(), lo_tmp=lo;
			if (lo>hi) continue;
			root[i]=++cnt;
			
			// deal lo
			int u=root[x], v=root[i], ct=0, dir=0;
			while (sz[u]>1){
				q[++ct]=v;
				if (lo<=sz[ls[u]])
					rs[v]=rs[u],
					ls[v]=++cnt,
					dir=0,
					u=ls[u],
					v=ls[v];
				else 
					lo-=sz[ls[u]],
					rs[v]=++cnt,
					dir=1,
					u=rs[u],
					v=rs[v];
			}
			if (!ct) q[++ct]=v; else --cnt;
			if (dir) rs[q[ct]]=u;else ls[q[ct]]=u;
			for (int j=ct;j;j--) pushup(q[j]);
			
			// deal hi
//			u=root[x], v=root[i];
			u=root[i], v=root[i]=++cnt, ct=0, dir=0;
			hi-=lo_tmp-1;
			while (sz[u]>1){
				q[++ct]=v;
				if (hi>sz[ls[u]])
					hi-=sz[ls[u]],
					ls[v]=ls[u],
					rs[v]=++cnt,
					dir=1,
					u=rs[u],
					v=rs[v];
				else
					ls[v]=++cnt,
					dir=0,
					u=ls[u],
					v=ls[v];
			}
			if (!ct) q[++ct]=v; else --cnt;
			if (dir) rs[q[ct]]=u;else ls[q[ct]]=u;
			for (int j=ct;j;j--) pushup(q[j]);
		}
		else{
			int x=read(), y=read();
			root[i]=++cnt;
			ls[cnt]=root[x];
			rs[cnt]=root[y];
			pushup(root[i]);
		}
	}
	cout<<f[root[n-1]]<<endl;
    return 0;
}
