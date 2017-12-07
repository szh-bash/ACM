#include<cstdio>
#include<string.h>
#include<iostream> 
double g[10001];
int cnt[27];
char s[10001];
int main()
{
    int n,i;
    scanf("%s",s);
    n=strlen(s);
    for(i=0;i<n;++i)
        cnt[s[i]-'A']++;
    for(i=1;i<n;++i)
        g[i+1]=2*g[i]-g[i-1]+(n-1.0)/(n-i);
    double ans=0;
    for(i=0;i<26;++i)
        ans+=-cnt[i]*g[n]/n+g[cnt[i]];
    printf("%.1lf\n",ans);
    std::cout<<g[n]<<' '<<g[1];
    return 0;
}
