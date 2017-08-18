#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mo 1000000007
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
	freopen("h.ans","w",stdout);
	int T;
	cin>>T;
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
				for (int k=1;k<=i;k++)
					for (int l=1;l<=j;l++){
						bool flag=1;
						for (int x=k;x<=i && flag;x++)
							for (int y=l;y<=j;y++)
								if (a[x][y]!=a[i][j]){
									flag=0;
									break;
								}
						if (flag) ans=(ans+(i-k+1)*(j-l+1))%mo;
					}
				//cout<<ans<<endl;
			}
		cout<<ans<<endl;
	}
	return 0;
}
