#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f[6001],s[6001],c[6001];
int main()
{
    int n;
    while(cin>>n)
    {
        memset(s,0,sizeof(s));
        memset(c,0,sizeof(c));
        memset(f,0,sizeof(f));

        for(int i=1;i<=n;i++)
        {
            cin>>c[i];
            s[i]=s[i-1]+c[i];
            f[i]=c[i];
        }

        for(int len=2;len<=n;len++)
         for(int i=1;i<=n-len+1;i++)
         f[i]=max(c[i]+s[i+len-1]-s[i]-f[i+1],c[i+len-1]+s[i+len-2]-s[i-1]-f[i]);

        cout<<f[1]<<"\n";
    }
    return 0;
}
