#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define mo 1000000007
#define N 3005
int n, h[N], rt[N], lt[N], dp[N][N];
int sum[N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        ch=='-'?q=-1:0,
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int add(int a, int b){
    return a+b>=mo?a+b-mo:a+b;
}
int main(){
    n=read();
    for (int i=1;i<=n;i++) h[i]=read();
    for (int i=1;i<=n;i++){
        for (int j=i;j && h[j]>=h[i];j--) lt[i]=j;
        for (int j=i;j<=n && h[j]>=h[i];j++) rt[i]=j;
    }
    for (int i=0;i<=n;i++) sum[i]=1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++)
            if (lt[j]<=i && i<=rt[j])
                dp[i][j]=sum[j];
            else dp[i][j]=0;
        sum[0]=0;
        for (int j=1;j<=n;j++) sum[j]=add(sum[j-1],dp[i][j]);
    }
    cout<<sum[n]<<endl;
    return 0;
}