/*
??????????????
????????
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 5010
#define MAX 10010
#define lch(i) ((i)<<1)
#define rch(i) ((i)<<1|1)

int res;
struct segment
{
    int l,r,h,v;
}sx[2*N],sy[2*N];
struct node{
    int l,r,cnt,len;
    int mid()
    { return (l+r)>>1; }
}t[2*MAX*4];

int cmp(struct segment p ,struct segment q)
{
    return p.h<q.h;
}

void build(int l ,int r ,int rt)
{
    t[rt].l=l; t[rt].r=r; t[rt].cnt=t[rt].len=0;
    if(l==r) return ;
    int mid=t[rt].mid();
    build(l,mid,lch(rt));
    build(mid+1,r,rch(rt));
}

void cal(int rt)
{
    if(t[rt].cnt) //??????
        t[rt].len=t[rt].r-t[rt].l+1;
    else if(t[rt].l == t[rt].r) //????
        t[rt].len=0;
    else //???????
        t[rt].len=t[lch(rt)].len + t[rch(rt)].len;
}

void updata(int l ,int r ,int v ,int rt)
{
    if(t[rt].l==l && t[rt].r==r) //????
    {
        t[rt].cnt += v;
        cal(rt);
        return ;
    }
    int mid=t[rt].mid();
    if(r<=mid)      updata(l,r,v,lch(rt));
    else if(l>mid)  updata(l,r,v,rch(rt));
    else
    {
        updata(l,mid,v,lch(rt));
        updata(mid+1,r,v,rch(rt));
    }
    cal(rt);
}

void solve(int left ,int right ,struct segment *s , int n)
{
    build(left,right-1,1); //???????,????????????
    int ans=0 , prelen=0;
    for(int i=0; i<n; i++) //updata?????
    {
        updata(s[i].l , s[i].r-1 , s[i].v ,1);
        ans += abs(t[1].len-prelen);
        prelen=t[1].len;
    }
    res += ans;
}

int main()
{
	freopen("1.in","r",stdin);
	freopen("std.out","w",stdout);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        { puts("0"); continue;}
        int i,j, maxx=-MAX, minx=MAX, maxy=-MAX, miny=MAX;
        for(i=0,j=0; i<n; i++,j+=2)
        {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            maxx=max(maxx,x2);  minx=min(minx,x1);
            maxy=max(maxy,y2);  miny=min(miny,y1);
            //???????
            sx[j].l=x1;   sx[j].r=x2;   sx[j].h=y1;   sx[j].v=1;
            sx[j+1].l=x1; sx[j+1].r=x2; sx[j+1].h=y2; sx[j+1].v=-1; 
            //???????
            sy[j].l=y1;   sy[j].r=y2;   sy[j].h=x1;   sy[j].v=1;
            sy[j+1].l=y1; sy[j+1].r=y2; sy[j+1].h=x2; sy[j+1].v=-1;
        }
        sort(sx,sx+j,cmp); //??????????
        sort(sy,sy+j,cmp); //??????????

        res=0;
        solve(minx,maxx,sx,j); //???????
        solve(miny,maxy,sy,j); //???????
        printf("%d\n",res);
    }
    return 0;
}
