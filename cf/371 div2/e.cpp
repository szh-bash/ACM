#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int n,a[3005],b[3005];
long long c[3005][3005],f[3005][3005];
long long ans=(long long)1000000000*1000000;
inline bool cmp(int a,int b){return a>b;}
int main()
{
    n=read();
    for(int i=1;i<=n;i++)
        a[i]=b[i]=read()-i;
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
        f[i][0]=(long long)1000000000*1000000;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            c[i][j]=f[i-1][j]+abs(b[j]-a[i]);
            f[i][j]=min(f[i][j-1],c[i][j]);
        }
        ans=f[n][n];
    cout<<ans<<endl;
    return 0;
}
