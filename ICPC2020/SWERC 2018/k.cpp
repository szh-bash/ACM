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
ll readll(){
    ll p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
#define N 705
char s[N];
int n, dp[N][N], p[N], f[N][N];
void kmp(int st){
	p[st]=st-1;
	for (int i=st+1, j=st-1;i<=n;i++){
		while (j>=st && s[j+1]!=s[i]) j=p[j];
		if (s[j+1]==s[i]) ++j;
		p[i]=j;
		if ((p[i]-st+1)*2>=(i-st+1) && (i-st+1)%(i-p[i])==0) f[st][i]=i-p[i];
		else f[st][i]=0;
	}
}
void init(){
	n=read();
	scanf("%s", s+1);
	p[1]=0;
	for (int i=1;i<=n;i++) kmp(i);
}
int main(){
	init();
	for (int i=n;i;i--){
		dp[i][i]=1;
		for (int j=i+1;j<=n;j++){
			dp[i][j]=n+1;
			for (int k=i;k<j;k++)
				dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]);
			if (f[i][j])
				for (int k=1;k*f[i][j]<=j-i+1;k++)
					if ((j-i+1)%(k*f[i][j])==0)
						dp[i][j]=min(dp[i][j], dp[i][i+k*f[i][j]-1]);
		}
	}
	cout<<dp[1][n]<<endl;
    return 0;
}
