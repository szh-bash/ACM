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

#define M 1000
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, f[M][M];
double w[M][M];
const double eps= 1e-5;
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
	n=read();
	for (int i=1;i<=n;i++){
		int u=read()+5, v=read()+5;
		scanf("%lf", &w[u][v]);
	}
	for (int q=read();q;q--){
		int ans=0;
		int u1=read()+5, v1=read()+5, u2=read()+5, v2=read()+5, duu=abs(u2-u1), dvv=abs(v2-v1);
		if (u1>u2) swap(u1,u2), swap(v1,v2);
		if (duu>=dvv){
			double dv=(double)(v2-v1)/duu, si=sqrt((double)duu*duu/(dvv*dvv+duu*duu));
			for (int j=u1;j<=u2;j++){
				double y=(j-u1)*dv+v1;
				//cout<<y-5<<endl;
				int yp=ceil(y), yd=floor(y);
				for (int k=0;k<2;k++){
					if (w[j][yp+k] && si*si*(yp+k-y)*(yp+k-y)<w[j][yp+k]*w[j][yp+k]-eps){
						//ans++;
						if (!(j==u1 && v2<v1 && k==1 || j==u2 && v2>v1 && k==1))ans++;
						//cout<<j-5<<' '<<yp+k-5<<' '<<si*(yp+k-y)<<' '<<w[j][yp+k]<<endl;
					}
					if (w[j][yd-k] && si*si*(-yd+k+y)*(-yd+k+y)<w[j][yd-k]*w[j][yd-k]-eps && yp+k!=yd-k){
						//ans++;
						if (!(j==u2 && v2<v1 && k==1 || j==u1 && v2>v1 && k==1)) ans++;
						//cout<<j-5<<' '<<yd-k-5<<' '<<si*(-yd+k+y)<<' '<<w[j][yd-k]<<endl;
					}
				}
			}
			printf("%d\n", ans);
			continue;
		}
		if (duu<dvv){
			if (v1>v2) swap(u1,u2), swap(v1,v2);
			double du=(double)(u2-u1)/dvv, si=sqrt((double)dvv*dvv/(dvv*dvv+duu*duu));
			for (int j=v1;j<=v2;j++){
				double x=(j-v1)*du+u1;
				//cout<<y-5<<endl;
				int xp=ceil(x), xd=floor(x);
				for (int k=0;k<2;k++){
					if (w[xp+k][j] && si*si*(xp+k-x)*(xp+k-x)<w[xp+k][j]*w[xp+k][j]-eps)
						if (!(j==v2 && u2>u1 && k==1 || j==v1 && u2<u1 && k==1)) ans++;
						//ans++;
					if (w[xd-k][j] && si*si*(-xd+k+x)*(-xd+k+x)<w[xd-k][j]*w[xd-k][j]-eps && xp+k!=xd-k)
						if (!(j==v1 && u2>u1 && k==1 || j==v2 && u2<u1 && k==1)) ans++;
						//ans++;
				}
			}
			printf("%d\n", ans);
			continue;
		}
	}
    return 0;
}
/*
5
4 2 0.6
7 3 0.7
8 5 0.8
1 3 0.7
3 4 0.4
2
3 1 9 6
3 4 7 2
*/
