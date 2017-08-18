//orz Tls
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct zsm{
	long long x, y, z;
}l[1100];
int n, m, cnt;
long long ss,s2,ans,sum;
int f[1100][1100];
char a[1100][1100], s[1100];
int main(){
	freopen("h.in","r",stdin);
	freopen("h.out","w",stdout);
	int T;
	cin>>T;
	for (int i=1;i<=1000;i++) a[0][i]=a[i][0]='s';
	while (T--){
		cin>>n>>m;
		ans=0;
		for (int i=1;i<=n;i++){
			scanf("%s", s);
			for (int j=1;j<=m;j++)
				a[i][j]=s[j-1];
		}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++){
				if (a[i][j]==a[i-1][j]) f[i][j]=f[i-1][j]+1;
					else f[i][j]=1;
				if (a[i][j]==a[i][j-1]){
					while (cnt && l[cnt].y>=f[i][j]){
						sum=sum-l[cnt].y*l[cnt].z*(l[cnt].y+1)*(l[cnt].z+1)/4;
						s2=s2-l[cnt].y*(l[cnt].y+1)*l[cnt].z/2;
						ss=ss-l[cnt].z*l[cnt].y*(l[cnt].y+1)*(j-l[cnt].x-1)/2;
						cnt--;
					}
					l[++cnt].y=f[i][j];
					l[cnt].x=j;
					l[cnt].z=j-l[cnt-1].x;
					sum=sum+l[cnt].y*l[cnt].z*(l[cnt].y+1)*(l[cnt].z+1)/4;
					ss=ss+s2;
					ans=ans+sum+ss;
					s2=s2+l[cnt].z*(l[cnt].y+1)*l[cnt].y/2;
				}
				else{
					cnt=1;
					l[0].x=j-1;
					l[cnt].y=f[i][j];
					l[cnt].x=j;
					l[cnt].z=1;
					ans=ans+(f[i][j]+1)*f[i][j]/2;
					sum=l[cnt].y*l[cnt].z*(l[cnt].y+1)*(l[cnt].z+1)/4;
					s2=l[cnt].z*(l[cnt].y+1)*l[cnt].y/2;
					ss=0;
				}
			}
		cout<<ans<<endl;
	}
	return 0;
}
