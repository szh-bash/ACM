#include <bits/stdc++.h>
#include<tr1/unordered_map>
#define mo 500000
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
using namespace std::tr1;
unordered_map <int, int> mp[2];
int n, k, cnt, trans[2][800000], l[2][mo+100], g[10], a[10], cg[10];
double f[2][800000], ans[10];
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
	g[0]=1;
	while (~scanf("%d%d", &n, &k)){
		int m=0;
		for (int i=1;i<=n;i++)
			a[i]=read(),
			g[i]=g[i-1]*(k+1),
			m+=a[i]*g[i-1],
			ans[i]=0;
		mp[0].clear();
		//mp[1].clear(); 
		trans[0][mp[0][m]=cnt=1]=m;
		f[0][1]=1;
		l[0][1]=m;
		for (int r=0, ri=1, o=1, flag=0;!flag; o^=1, ri=r, r=0){
			cnt=0;
			mp[o].clear();
			for (int le=1;le<=ri;le++){
				int u=l[o^1][le];
				int sum=0;
				for (int j=1;j<=n;j++){
					cg[j]=u%(k+1), u/=k+1;
					sum+=cg[j];
				}
				u=mp[o^1][l[o^1][le]];
				if (sum==k){
					flag=1;
					int ma=-1, ct=0;
					for (int j=1;j<=n;j++)
						if (cg[j]>ma) ma=cg[j], ct=1;
						else
							if (cg[j]==ma) ct++;
					for (int j=1;j<=n;j++)
						if (cg[j]==ma) ans[j]+=f[o^1][u]/ct;
					continue;
				}
				for (int j=1;j<=n;j++){
					int v=0;
					double p=(double)cg[j]/sum;
					for (int k=1;k<=n;k++) v+=(cg[k]+(j==k))*(g[k-1]);
					if (!mp[o][v]){
						trans[o][mp[o][v]=++cnt]=v;
						l[o][++r]=v;
						f[o][cnt]=0;
					}
					v=mp[o][v];
					f[o][v]+=f[o^1][u]*p;
				}
			}
		}
		for (int i=1;i<=n;i++){
			printf("pub %d: %.2lf %%\n", i, ans[i]*100);
			//puts("%");
		}
	}
    return 0;
}
