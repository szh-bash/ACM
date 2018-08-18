#include <bits/stdc++.h>
#define mo 500000
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
map <int, int> mp;
int n, k, cnt, trans[8000000], l[mo+100], g[10], a[10], cg[10];
double f[8000000], ans[10];
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
		//cout<<m<<endl;
		mp.clear();
		trans[mp[m]=cnt=1]=m;
		f[1]=1;
		l[1]=trans[1];
		int tmp=0, tmp2=1;
		for (int le=0, ri=1;le!=ri;){
			//cout<<le<<' '<<ri<<endl;
			int u=l[++le==mo?le=0:le];
			int sum=0;
			for (int j=1;j<=n;j++){
				cg[j]=u%(k+1), u/=k+1;
				sum+=cg[j];
				//cout<<cg[j]<<' ';
			}//cout<<endl;
			u=mp[l[le]];
			if (sum==k){
				int ma=-1, ct=0;
				for (int j=1;j<=n;j++)
					if (cg[j]>ma) ma=cg[j], ct=1;
					else
						if (cg[j]==ma) ct++;
				for (int j=1;j<=n;j++)
					if (cg[j]==ma) ans[j]+=f[u]/ct;
				continue;
			}
			if (sum>tmp){
				for (int i=tmp0;
				tmp=sum;
			}
			for (int j=1;j<=n;j++){
				int v=0;
				double p=(double)cg[j]/sum;
				for (int k=1;k<=n;k++) v+=(cg[k]+(j==k))*(g[k-1]);
				//cout<<trans[u]<<' '<<v<<endl;
				if (!mp[v]){
					trans[mp[v]=++cnt]=v;
					l[++ri==mo?ri=0:ri]=cnt;
					f[cnt]=0;
				}
				v=mp[v];
				f[v]+=f[u]*p;
			}
		}
		for (int i=1;i<=n;i++){
			printf("pub %d: %.2lf ", i, ans[i]*50);
			puts("%");
		}
	}
    return 0;
}
