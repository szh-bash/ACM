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
#define N 2000
#define M 10
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
const ll INF=(ll)1000000000*1000000000;
int n, m, flag[N][M], k, a[N];
struct qlz{
	ll min, max;
}f[N][M];
char s[M];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
void push(int u, int v){
	int w=u+1, t=v+1;
	flag[w][t]=flag[w][v]=1;
	if (s[v]=='+'){
		f[w][t].max=max(f[w][t].max,f[u][v].max+a[w]);
		f[w][t].min=min(f[w][t].min,f[u][v].min+a[w]);
	}
	if (s[v]=='-'){		
		f[w][t].max=max(f[w][t].max,f[u][v].max-a[w]);
		f[w][t].min=min(f[w][t].min,f[u][v].min-a[w]);
	}
	if (s[v]=='*'){
		f[w][t].max=max(f[w][t].max,max(f[u][v].max*a[w],f[u][v].min*a[w]));
		f[w][t].min=min(f[w][t].min,min(f[u][v].min*a[w],f[u][v].max*a[w]));
	}
	if (s[v]=='/'){
		f[w][t].max=max(f[w][t].max,max(f[u][v].max/a[w],f[u][v].min/a[w]));
		f[w][t].min=min(f[w][t].min,min(f[u][v].min/a[w],f[u][v].max/a[w]));
	}
	f[w][v].max=max(f[w][v].max,f[u][v].max);
	f[w][v].min=min(f[w][v].min,f[u][v].min);
}
int main(){
	for (int _=read();_;_--){
		n=read();m=read();k=read();
		for (int i=1;i<=n;i++) a[i]=read();
		scanf("%s", s);
		memset(flag,0,sizeof(flag));
		flag[0][0]=1;
		for (int i=0;i<=n;i++)
			for (int j=0;j<=m;j++)
				f[i][j].max=-INF,
				f[i][j].min=INF;
		f[0][0].min=f[0][0].max=k;
		ll ans=-INF;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++)
				if (flag[i][j]) push(i,j);
			if (flag[i+1][m]) ans=max(ans,f[i+1][m].max);
		}
		cout<<ans<<endl;
	}
    return 0;
}
