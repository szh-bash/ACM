#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int k, A, B, C;
double f[2][8][8][8], g[2][8][8][8];
int main(){
	int T;
	cin>>T;
	while (T--){
		scanf("%d%d%d%d", &k, &A, &B, &C);
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		g[1][A][B][C]=1;
		for (int i=1;i<=k;i++){
			for (int a=0;a<=7;a++)
				for (int b=0;a+b<=7;b++)
					for (int c=0;a+b+c<=7;c++){
							double p=1.0/(a+b+c+1);
							f[(i+1)&1][a][b][c]+=(g[i&1][a][b][c]+f[i&1][a][b][c])*p;
							g[(i+1)&1][a][b][c]+=g[i&1][a][b][c]*p;
							if (a)
								f[(i+1)&1][a-1][b][c]+=a*p*f[i&1][a][b][c],
								g[(i+1)&1][a-1][b][c]+=a*p*g[i&1][a][b][c];
							if (b)
								if (a+b+c<7)
									f[(i+1)&1][a+1][b-1][c+1]+=b*p*f[i&1][a][b][c],
									g[(i+1)&1][a+1][b-1][c+1]+=b*p*g[i&1][a][b][c];
								else
									f[(i+1)&1][a+1][b-1][c]+=b*p*f[i&1][a][b][c],
									g[(i+1)&1][a+1][b-1][c]+=b*p*g[i&1][a][b][c];
							if (c)
								if (a+b+c<7)
									f[(i+1)&1][a][b+1][c]+=c*p*f[i&1][a][b][c],
									g[(i+1)&1][a][b+1][c]+=c*p*g[i&1][a][b][c];
								else
									f[(i+1)&1][a][b+1][c-1]+=c*p*f[i&1][a][b][c],
									g[(i+1)&1][a][b+1][c-1]+=c*p*g[i&1][a][b][c];
						}
			for (int a=0;a<=7;a++)
				for (int b=0;a+b<=7;b++)
					for (int c=0;a+b+c<=7;c++)
						f[i&1][a][b][c]=g[i&1][a][b][c]=0;
		}
		double ans=0;
		for (int a=0;a<=7;a++)
			for (int b=0;a+b<=7;b++)
				for (int c=0;a+b+c<=7;c++)
					ans+=f[(k+1)&1][a][b][c];
		printf("%.2lf\n", ans);
	}
	return 0;
}
