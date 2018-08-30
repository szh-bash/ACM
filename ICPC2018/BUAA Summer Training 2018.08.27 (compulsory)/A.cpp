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
#define N 200
#include <tr1/unordered_map>
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}

ll f[N+5][N+5];

int main(){
	f[0][0]=1;
	for (int i=1;i<=N;i++){
		f[i][0]=1;
		for (int j=1;j<=N;j++)
			f[i][j]=f[i-1][j-1]+f[i][j-1];
	}
	int l,k;
	ll ans=0;
	cin>>l>>k;
	for (int i=0;i*k<=l;i++){
		int ct=l-i*k;
		for (int j=0;j<=ct;j++)
			if ((i+j)%2){
				ans+=f[i+j][i];
			}
	}
	cout<<ans<<endl;
    return 0;
}
