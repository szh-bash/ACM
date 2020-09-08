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
#define N 200005
#define M (N*20)
int n, m, cnt;
int tag[N], flag[N], f[N];
int nex[M], nu[M], nex2[M], nu2[M];
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void add2(int u, int v){
	nex2[++cnt]=nex2[u];nex2[u]=cnt;nu2[cnt]=v;
}
void solve(){
	cnt=n=read();
	m=n-f[n]+f[n/2]-1;
	printf("%d\n", m/2);
	for (int i=2;i<=n;i++) tag[i]=nex2[i]=0;
	for (int i=n/2+1;i<=n;i++)
		if (flag[i] && (i&1))
			for (int j=nex[i];j;j=nex[j])
				add2(nu[j],i);
	for (int i=2;i<=n;i++)
		if (nex2[i]){
			int j=nex2[i];
			while (1){
				while (j && tag[nu2[j]]) j=nex2[j];
				if (!j) break;
				int j2=nex2[j];
				while (j2 && tag[nu2[j2]]) j2=nex2[j2];
				int u=nu2[j], v=nu2[j2];
				if (!j2) break;
				tag[u]=tag[v]=1;
				printf("%d %d\n", u, v);
				j=nex2[j2];
			}
		}
	for (int i=n/2+1;i<=n;i++)
		if (flag[i] && (i&1) && !tag[i]){
			tag[nu[nex[i]]]=tag[i]=1;
			printf("%d %d\n", i, nu[nex[i]]);
		}
	for (int i=2;i<=n/2;i++)
		if ((i&1) && (!tag[i]))
			printf("%d %d\n", i, i<<1),
			tag[i]=tag[i<<1]=1;
	int p=0;
	for (int i=2;i<=n;i+=2)
		if (!tag[i])
			if (!p) p=i;
			else printf("%d %d\n", p, i), p=0;
}
int main(){
	cnt=N;
	for (int i=2;i<N;i++){
		f[i]=f[i-1];
		if (!flag[i]){
			for (int j=2;j*i<N;j++)
				flag[i*j]=1,
				add(j*i,i);
			f[i]++;
		}
	}
	for (int _=read();_;_--) solve();
    return 0;
}
