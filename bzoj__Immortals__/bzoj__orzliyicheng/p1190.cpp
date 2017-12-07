#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<map>
#include<ctime>
#include<set>
#include<queue>
#include<cmath>
#include<vector>
#include<bitset>
#include<functional>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;

typedef long long LL;
typedef double ld;

const int NUM=40;
const int MAX=1000+10;

int n,W;
pair<int,int> s[MAX];
int c[MAX],d[MAX],f[NUM][MAX];

int main()
{
    while(1)
    {
        memset(f,0,sizeof f);
        memset(c,0,sizeof c);
        memset(d,0,sizeof d);
        scanf("%d%d",&n,&W);
        if(n==-1)break;
        int i,j,now,k;
        for(i=1;i<=n;++i)
        {
            scanf("%d%d",&s[i].x,&s[i].y);
            for(now=s[i].x;now%2==0;now/=2)
                ++d[i];
            c[i]=now;
        }
        for(i=0;i<31;++i)
        {
            if(i!=0)
                for(j=0;j<MAX;++j)
                {
                    if((LL)j*(1<<(i-1))>W)continue;
                    int p=( W%(1<<(i-1))+j*(1<<(i-1)) ) - W%(1<<i);
                    if(p<0)p=0;
                    f[i][(p+(1<<i)-1)/(1<<i)]=max(f[i][(p+(1<<i)-1)/(1<<i)],f[i-1][j]);
                }
            for(k=1;k<=n;++k)
                if(d[k]==i)
                    for(j=MAX-1;j>=0;--j)
                    {
                        if((LL)j*(1<<i)>W)continue;
                        int nw=j*(1<<i)+s[k].x;
                        if(nw/(1<<i)>=MAX)
                            continue;
                        f[i][nw/(1<<i)]=max(f[i][nw/(1<<i)],f[i][j]+s[k].y);
                    }
        }
        int ans=0;
        for(i=0;i<MAX;++i)
        {
            if((LL)i*(1<<30)>W)break;
            ans=max(ans,f[30][i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
