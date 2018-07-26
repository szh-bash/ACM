#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define M 37
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
short n, m[5], v[5], ans, f[2][M][M][M][M];
short w[2][M][M][M][M][M+1];
struct qlz{
	int v[5];
}l[M];
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
	for (int i=1;i<=n;i++)
		for (int j=0;j<5;j++) l[i].v[j]=read();
	for (int i=0;i<4;i++) v[i]=read();
	int o=1;
	for (int i=1;i<=n;i++, o^=1){
		for (int j=0;j<4;j++) m[j]=v[j]-l[i].v[j]+1;
		for (int p1=0;p1<m[0];p1++)
			for (int p2=0;p2<m[1];p2++)
				for (int p3=0;p3<m[2];p3++)
					for (int p4=0;p4<m[3];p4++){
						if (f[o^1][p1][p2][p3][p4]>f[o][p1][p2][p3][p4])
							f[o][p1][p2][p3][p4]=f[o^1][p1][p2][p3][p4],
							w[o][p1][p2][p3][p4]=w[o^1][p1][p2][p3][p4],
							* (w[o][p1][p2][p3][p4]+(++(*w[o][p1][p2][p3][p4]))=i;
						if (f[o^1][p1][p2][p3][p4]+l[i].v[4]>f[o][p1+l[i].v[0]][p2+l[i].v[1]][p3+l[i].v[2]][p4+l[i].v[3]])
							f[o][p1+l[i].v[0]][p2+l[i].v[1]][p3+l[i].v[2]][p4+l[i].v[3]]=f[o^1][p1][p2][p3][p4]+l[i].v[4],
							w[o][p1+l[i].v[0]][p2+l[i].v[1]][p3+l[i].v[2]][p4+l[i].v[3]]=w[o^1][p1][p2][p3][p4],
							* (w[o][p1+l[i].v[0]][p2+l[i].v[1]][p3+l[i].v[2]][p4+l[i].v[3]]+(++(*w[o^1][p1][p2][p3][p4])))=i;
					}
		for (int p1=0;p1<M;p1++)
			for (int p2=0;p2<M;p2++)
				for (int p3=0;p3<M;p3++)
					for (int p4=0;p4<M;p4++)
						f[o^1][p1][p2][p3][p4]=0;
	}
	short * w;
	for (int p1=0;p1<M;p1++)
			for (int p2=0;p2<M;p2++)
				for (int p3=0;p3<M;p3++)
					for (int p4=0;p4<M;p4++)
						if (f[o^1][p1][p2][p3][p4]>ans) ans=f[o^1][p1][p2][p3][p4], p=w[o^1][p1][p2][p3][p4];
	cout<<ans<<endl;
    return 0;
}
