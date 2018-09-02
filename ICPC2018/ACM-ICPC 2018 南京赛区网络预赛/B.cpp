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
#define M 106
#define N 100006
#define K 200000
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, m, k, f[N][M], num[N], g[N];
struct zsa{
	int x, y;
}l[K];
struct dddl{
	int n, len;
}q[N];
bool cmp(zsa a, zsa b){
	if (a.x<b.x) return 1;
	if (a.x>b.x) return 0;
	return a.y<b.y;
}
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	for (int _=read(), T=1;_;_--, T++){
		n=read();m=read();k=read();
		for (int i=1;i<=k;i++) l[i].x=read(), l[i].y=read();
		sort(l+1,l+1+k,cmp);
		for (int i=1;i<=n;i++) num[i]=g[i]=0;
		for (int i=1;i<=k;i++) f[l[i].x][++num[l[i].x]]=l[i].y;
		ll ans=0;
		for (int j=1;j<=m;j++){	
			int tail=0;
			ll sum=0;
			q[0].len=q[0].n=0;
			for (int i=1;i<=n;i++){
				while (f[i][g[i]]<=j && g[i]<num[i] && f[i][g[i]+1]<=j) g[i]++;
				int len=j-f[i][g[i]];
				while (tail && q[tail].len>=len && q[tail-1].len>=len) sum-=(i-q[tail].n)*(q[tail].len-q[tail-1].len), tail--;
				//cout<<i<<' '<<j<<' '<<len<<' '<<tail<<endl;
				if (q[tail].len<len){
					sum+=len;
					ans+=sum;
					q[++tail].len=len;
					q[tail].n=i;
				}
				else{
					if (!len) q[tail].n=i, sum=0;
					else
						sum-=(i-q[tail].n)*(q[tail].len-len),
						sum+=len,
						ans+=sum,
						q[tail].len=len;
				}
				//cout<<sum<<endl;
			}
		}
		printf("Case #%d: %lld%s", T, ans, _!=1?"\n":"");
	}
    return 0;
}
