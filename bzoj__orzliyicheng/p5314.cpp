#include<set>
#include<map>
#include<ctime>
#include<queue>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define inf (900000000LL)
#define mp make_pair
#define pli pair<ll,int>
#define pii pair<int,int>
#define mo 1000000007
typedef long long ll;
using namespace std;
int read(){
	int x=0,p=1;char ch=getchar();
	while(ch<'0'||ch>'9'){ch=='-'?p=-1:0;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*p;
}
void link(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
int main(){
	cnt=n=read();k=read();
	for (int i=1;i<n;i++){
		int u=read(), v=read();
		link(u,v);
		link(v,u);
	}
	dfs(1,0);
	cout<<(f[1][k][2]+f[1][k][3])%mo<<endl;
	return 0;
}
