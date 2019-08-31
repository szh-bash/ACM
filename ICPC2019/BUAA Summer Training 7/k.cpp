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
#define N 250001
#define Q 251
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, t;
int q[1001], x[1001], a[1001];
int f[N][Q], g[N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int add(int &a, int b){
	a+=b;
	if (a>=mo) a-=mo;
	return a;
}
int main(){
	freopen("kebab.in", "r", stdin);
	freopen("kebab.out", "w", stdout);
	n=read();t=read();
	for (int i=1;i<=n;i++) q[i]=read(), x[i]=read(), a[i]=q[i]-x[i];
	int sum=0;
	g[0]=1;
	for (int i=1;i<=n;i++){
		for (int j=sum+1;j<=sum+q[i];j++){
			for (int k=0;k<=j-sum && k<=a[i];k++){
				
				if (j>sum+1) add(f[j][k], f[j-1][k]);
				else
					if (!k) add(f[j][k], g[j-1]);
				
				if (k)
					if (j-(t+1)>sum) add(f[j][k], f[j-(t+1)][k-1]);
					else 
						if (k==1) add(f[j][k], g[max(0,j-(t+1))]);
				
				add(g[j], f[j][k]);
//				cout<<i<<' '<<j<<' '<<k<<' '<<f[j][k]<<endl;
			}
//			cout<<i<<' '<<j<<' '<<g[j]<<endl;
		}
		sum+=q[i];
	}
//	cout<<sum<<endl;
	cout<<g[sum]<<endl;
    return 0;
}
