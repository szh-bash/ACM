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
#define INF 999999999
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
map<string,int>mp;
int n, cnt;
char s0[20], s1[20];
double p, f[400000];
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
	mp["pink"]=cnt=1;
	f[1]=0;
	for (int i=1;i<=n;i++){
		scanf("%s%s", s0, s1);scanf("%lf", &p);
		
		string s="";
		int u, v;
		s=s0;
		if (!mp[s]) mp[s]=++cnt, f[cnt]=-INF;
		u=mp[s];
		s=s1;
		if (!mp[s]) mp[s]=++cnt, f[cnt]=-INF;
		v=mp[s];
		
		p=log(p);
		if (f[v]+p>f[u]) f[u]=f[v]+p;
	}
	if (!mp["blue"]){
		cout<<0<<endl;
		return 0;
	}
	double ans=exp(f[mp["blue"]]);
	if (ans>10) ans=10;
	printf("%.8lf\n", ans);
    return 0;
}

/*
3
blue pink 1.0
red pink 1.5
blue red 1.0

4
orange pink 1.9
yellow orange 1.9
green yellow 1.9
blue green 1.9

8
red pink 1.9
orange red 1.9
yellow orange 1.9
green yellow 1.9
indigo green 0.6
violet indigo 0.6
purple violet 0.6
blue purple 0.6
*/
