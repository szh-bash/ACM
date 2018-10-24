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
#define N 5
#define H 40
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
double f[H][H][H][H][N][N];
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
int get(int h0, int h1, int h2, int h3, int p, int j){
	h0-=p==0;
	h1-=p==1;
	h2-=p==2;
	h3-=p==3;
	while (1){
		j=(j+1)%4;
		if (j==0 && h0) break;
		if (j==1 && h1) break;
		if (j==2 && h2) break;
		if (j==3 && h3) break;
	}
	return j;
}
int main(){
	for (int h0=1;h0<H;h0++)
		for (int h2=0;h2<H;h2++)
			for (int j=0;j<4;j++)
				f[h0][0][h2][0][j][2]=1;
	for (int h1=0;h1<H;h1++)
		for (int h2=0;h2<H;h2++)
			for (int h3=0;h3<H;h3++)
				for (int j=0;j<4;j++)
					if (!h1 && !h2 && h3) f[0][h1][h2][h3][j][3]=1;
					else f[0][h1][h2][h3][j][1]=1;
	for (int h0=1;h0<H;h0++)
		for (int h1=0;h1<H;h1++)
			for (int h2=0;h2<H;h2++)
				for (int h3=0;h3<H;h3++)
					if (h1 || h3)
					for (int j=0;j<4;j++){
						int flag=0;
						for (int k=1;k<4;k++)
							if (f[h0][h1][h2][h3][j][k]){
								flag=1;
								break;
							}
						if (flag) continue;
						if (!h1 && j==1 || !h2 && j==2 || !h3 && j==3) continue;
						if (j==0 || j==2){
							int p=0, cnt=0;
							double tmp=0;
							int j1=get(h0,h1,h2,h3,1,j);
							int j3=get(h0,h1,h2,h3,3,j);
							if (h1 && f[h0][h1-1][h2][h3][j+1][2]>tmp)
								tmp=f[h0][h1-1][h2][h3][j+1][2],
								p=1;
							else if (h1 && f[h0][h1-1][h2][h3][j+1][2]==tmp)
								cnt++;
							if (h3 && f[h0][h1][h2][h3-1][j+1][2]>tmp)
								tmp=f[h0][h1][h2][h3-1][j+1][2],
								p=3;
							else if (h3 && f[h0][h1][h2][h3-1][j+1][2]==tmp)
								cnt++;
							int t1, t3;
							if (p==1) t1=h1-1;else t1=h1;
							if (p==3) t3=h3-1;else t3=h3;
							for (int k=1;k<4;k++)
								if (cnt==1)
									f[h0][h1][h2][h3][j][k]=f[h0][t1][h2][t3][j+1][k];
								else
									f[h0][h1][h2][h3][j][k]=(f[h0][h1-1][h2][h3][j+1][k]+f[h0][h1][h2][h3-1][j+1][k])/2;
						}
						else{
								int tj=j==1?2:0;
								int tmp=0;
								int q[8];
								q[0]=0;
								if (h0 && f[h0-1][h1][h2][h3][get(h0,h1,h2,h3,0,j)][j]>tmp)
									tmp=f[h0-1][h1][h2][h3][get(h0,h1,h2,h3,0,j)][j],
									q[q[0]=1]=0;
								else if (h0 && f[h0-1][h1][h2][h3][get(h0,h1,h2,h3,0,j)][j]==tmp)
									q[++q[0]]=0;
							if (j!=1)
								if (h1 && f[h0][h1-1][h2][h3][get(h0,h1,h2,h3,1,j)][j]>tmp)
									tmp=f[h0][h1-1][h2][h3][get(h0,h1,h2,h3,1,j)][j],
									q[q[0]=1]=0;
								else if (h1 && f[h0][h1-1][h2][h3][get(h0,h1,h2,h3,1,j)][j]==tmp)
									q[++q[0]]=0;
								if (h2 && f[h0][h1][h2-1][h3][get(h0,h1,h2,h3,2,j)][j]>tmp)
									tmp=f[h0][h1][h2-1][h3][get(h0,h1,h2,h3,2,j)][j],
									q[q[0]=1]=2;
								else if (h2 && f[h0][h1][h2-1][h3][get(h0,h1,h2,h3,2,j)][j]==tmp)
									q[++q[0]]=2;
							if (j!=3)
								if (h3 && f[h0][h1][h2][h3-1][get(h0,h1,h2,h3,3,j)][j]>tmp)
									tmp=f[h0][h1][h2][h3-1][get(h0,h1,h2,h3,3,j)][j],
									q[q[0]=1]=3;
								else if (h3 && f[h0][h1][h2][h3-1][get(h0,h1,h2,h3,3,j)][j]==tmp)
									q[++q[0]]=3;
							for (int k=1;k<4;k++){
								for (int p=1;p<=q[0];p++)
									f[h0][h1][h2][h3][j][k]+=f[h0-(q[p]==0)][h1-(q[p]==1)][h2-(q[p]==2)][h3-(q[p]==3)][get(h0,h1,h2,h3,q[p],j)][k];
								f[h0][h1][h2][h3][j][k]/=q[0];
							}
						}
					}
	for (int _=read();_;_--){
		int h0=read(), h1=read(), h2=read(), h3=read();
		printf("%.6lf %.6lf %.6lf\n", f[h0][h1][h2][h3][0][2], f[h0][h1][h2][h3][0][1], f[h0][h1][h2][h3][0][3]); 
	}
    return 0;
}
