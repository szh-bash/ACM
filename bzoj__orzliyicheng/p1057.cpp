#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define maxn 2005
#define Len 10000000
#define read() (strtol(ipos,&ipos,10))
#define rep(x,l,r) for (x=l;x<=r;x++)
int n,m,a1,a2,top,sx[maxn],sh[maxn],h[maxn];
bool map[maxn][maxn];
char Input[Len],*ipos;
inline int sqr(int x){return x*x;}

void Init()
{
    int i,j;
    ipos=Input; fread(Input,Len,1,stdin);
    n=read(); m=read();
    rep(i,1,n) rep(j,1,m) map[i][j]=read();
}

void push(int h)
{
    int x=1;
    while (sh[top]>h)
    {
        a1=max(sqr(min(sh[top],sx[top])),a1);
        a2=max(sh[top]*sx[top],a2);
        top--;
        if (sh[top]>=h) sx[top]+=sx[top+1];
        else {x+=sx[top+1]; break;}
    }
    if (sh[top]==h) sx[top]+=x;
    else sh[++top]=h,sx[top]=x;
}

void Work()
{
    int i,j,now=0;
    a1=1; a2=1;
    rep(i,1,m)
    {
        if (map[1][i]+map[1][i-1]==1) now++; else now=1;
        a2=max(now,a2);
        h[i]=1;
    }
    rep(i,2,n)
    {
        rep(j,1,m)
        {
            if (map[i][j]+map[i][j-1]!=1) push(0);
            if (map[i][j]+map[i-1][j]==1) h[j]++;else h[j]=1;
            push(h[j]);
        }
        push(0);
    }
    printf("%d\n%d\n",a1,a2);
}

int main()
{
    Init();
    Work();
    return 0;
}
