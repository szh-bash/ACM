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
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
#define N 1000005
vector <int> g[N];
int flag[N], f[N], a[N];
int n;
int gcd(int a, int b){
	return (b?gcd(b, a%b):a);
}
int main(){
	for (int i=2;i<N;i++)
		if (!f[i]){
			for (int j=2;j*i<N;j++)
				g[i*j].push_back(i),
				f[i*j]=1;
		}
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int suf=a[n];
	int pairw=1;
	for (int i=n;i;i--){
		suf=gcd(suf,a[i]);
		if (a[i]==1) continue;
		if (flag[a[i]]) pairw=0;
		if (!pairw) continue;
		flag[a[i]]=1;
		for (int j=0, m=g[a[i]].size();j<m;j++)
			if (flag[g[a[i]][j]]) {pairw=0;break;}
			else flag[g[a[i]][j]]=1;
	}
	if (pairw) printf("pairwise coprime");
	else if (suf==1) printf("setwise coprime");
	else printf("not coprime");
	puts("");
    return 0;
}
