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

const int NUM=20;
const int MAX=1<<12;
const int INF=100000000;

int n,m;
string s[NUM],t[NUM];
int match[NUM][NUM];
string sl[NUM][NUM];
int f[MAX][NUM],come[MAX][NUM];

int cmp(string a,string b)
{
    if(a.size()!=b.size())return a.size()<b.size();
    else return a<b;
}

int main()
{
    int i,j,k,l=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
        cin>>s[i];
    sort(s+1,s+n+1,cmp);
    for(i=1;i<=n;++i)
    {
        int flag=1;
        for(j=i+1;j<=n;++j)
            if(s[j].find(s[i])!=s[j].npos)
                flag=0;
        if(flag)t[++m]=s[i];
    }
    for(n=m,i=1;i<=n;++i)
        s[i]=t[i];
    sort(s+1,s+n+1);
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            if(i!=j)
            {
                match[i][j]=-1;
                l=(int)s[i].size()-1;
                for(k=1,l=(int)s[i].size()-1;k<(int)s[i].size();++k,--l)
                    if((int)s[j].size()>=l && s[i].substr(k,l)==s[j].substr(0,l))
                    {
                        match[i][j]=k;
                        sl[i][j]=s[j].substr(l,s[j].size()-l);
                        break;
                    }
                if(match[i][j]==-1)
                {
                    match[i][j]=(int)s[i].size();
                    sl[i][j]=s[j];
                }
            }
    for(i=0;i<MAX;++i)
        for(j=0;j<NUM;++j)
            f[i][j]=INF;
    for(i=1;i<=n;++i)
        f[1<<(i-1)][i]=s[i].size();
    for(i=0;i<(1<<n);++i)
        for(j=1;j<=n;++j)
            if(f[i][j]!=INF)
            {
                for(k=1;k<=n;++k)
                    if(((i>>(k-1))&1)==0)
                    {
                        int c=i|(1<<(k-1));
                        if(f[c][k]>f[i][j]+match[k][j] || 
                                ( f[c][k]==f[i][j]+match[k][j] && sl[k][j]<sl[k][come[c][k]] ))
                        {
                            f[c][k]=f[i][j]+match[k][j];
                            come[c][k]=j;
                        }
                    }
            }
    int p=0;
    for(i=1;i<=n;++i)
        if(!p || f[(1<<n)-1][i]<f[(1<<n)-1][p] ||
                ( f[(1<<n)-1][i]==f[(1<<n)-1][p] && s[i]<s[p] ))
            p=i;
    int now=(1<<n)-1;
    while(now)
    {
        int temp=now&(~(1<<(p-1)));
        if(temp)cout<<s[p].substr(0,match[p][come[now][p]]);
        else cout<<s[p]<<endl;
        p=come[now][p];
        now=temp;
    }
    cout<<match[1][2]<<' '<<match[2][1]<<endl;
    return 0;
} 
