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
#define N 100
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int a[N][N], g[N][N], b[N][N], sum[N][N], n, m, t, T, M;
map <ull, int> mp;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
ull get(){
	ull p=0;
	for (int i=1+M;i<=n+M;i++)
		for (int j=1+M;j<=n+M;j++)
			p=(p<<1)+a[i][j];
	return p;
}
void calc(){
	for (int i=1+M;i<=n+M;i++)
		for (int j=1+M;j<=n+M;j++){
			int v=0;
			for (int p=i-m;p<=i+m;p++)
				v^=(sum[p][j+m]^sum[p][j-m-1])&b[p-i+m+1][2*m+1];
			g[i][j]=v;
		}
	for (int i=1+M;i<=n+M+m;i++)
		for (int j=1+M;j<=n+M+m;j++)
			a[i][j]=g[i][j],
			sum[i][j]=sum[i][j-1]^a[i][j];
}
void print(){
	int ans=0;
	for (int i=1+M;i<=n+M;i++)
		for (int j=1+M;j<=n+M;j++) ans+=a[i][j];
	printf("%d\n", ans);
}
int main(){
	for (int _=read();_;_--){
		mp.clear();
		n=read();M=read();t=read();
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) a[i+M][j+M]=read()%2;
		for (int i=1;i<=M;i++) for (int j=1;j<=M;j++) b[i][j]=read()%2;
		m=M>>1;
		int k=1;
		for (;k<=t;k++){
			mp[get()]=k;
			calc();
			if (mp[get()]) break;
		}
		if (k>t){
			print();
			continue;
		}
		int w=mp[get()]-1;
		T=k-w;
		t=(t-w)%T+1;
		while (t--) calc();
		print();
	}
    return 0;
}
