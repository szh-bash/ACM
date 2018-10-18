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
#define K 20
#define D 500
#define mo 1000000007
#define eps 1e-10
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int k;
ld f[K][D+5];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
ld power(ld a, int b){
	ld c=1;
	while (b){
		if (b&1) c=c*a;
		a=a*a;
		b>>=1;
	}
	return c;
}
int main(){
	for (int _=read();_;_--){
		k=read();
		for (int i=1;i<=k;i++){
			int c;
			ld p0, p=1, sum=0;
			scanf("%d%Lf", &c, &p0);
			ld q=1-p0;
			for (int j=1;j<=D;j++)
				sum+=p*q,
				p*=p0,
				f[i][j]=power(sum,c);
		}
		for (int i=1;i<=k;i++){
			ld ans=0, s0=0, s1;
			for (int j=1;j<=D;j++){
				s1=1;
				for (int w=1;w<=k;w++)
					if (w!=i) s1*=f[w][j];
				ans+=(s1-s0)*(1-f[i][j]);
				s0=s1;
			}
			printf("%.6Lf ", ans);
		}
		puts("");
	}
    return 0;
}
