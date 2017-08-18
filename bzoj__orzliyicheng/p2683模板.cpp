#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm> 
#define M 500500
using namespace std;
struct Query{
    int x,y,type;
    //type>0 修改
    //type==-1 查询 正
    //type==-3 查询 负
    Query() {}
    Query(int _,int __,int ___):
        x(_),y(__),type(___) {}
}mempool[800800],*q[800800],*nq[800800];
int n,m,ans[800800];
int stack[200200],top;
bool Compare(Query *q1,Query *q2)
{
    return q1->x < q2->x;
}
namespace BIT{
    int c[M],tim[M],T;
    inline void Update(int x,int y)
    {
        for(;x<=n;x+=x&-x)
        {
            if(tim[x]!=T)
                tim[x]=T,c[x]=0;
            c[x]+=y;
        }
    }
    inline int Get_Ans(int x)
    {
        int re=0;
        for(;x;x-=x&-x)
            if(tim[x]==T)
                re+=c[x];
        return re;
    }
}
void CDQ_Divide_And_Conquer(int l,int r)
{
    using namespace BIT;
    int i,j,mid=l+r>>1;
    if(l==r) return;
    int l1=l,l2=mid+1;
    for(i=l;i<=r;i++)
        if(q[i]-mempool<=mid)
            nq[l1++]=q[i];
        else nq[l2++]=q[i];
    memcpy(q+l,nq+l,sizeof(q[0])*(r-l+1) );
    CDQ_Divide_And_Conquer(l,mid);
    for(++T,j=l,i=mid+1;i<=r;i++)
    {
        for(;j<=mid&&q[j]->x<=q[i]->x;j++)
            if(q[j]->type>0)
                Update(q[j]->y,q[j]->type);
        if(q[i]->type<0)
            ans[q[i]-mempool]+=Get_Ans(q[i]->y)*(q[i]->type+2);
    }
    CDQ_Divide_And_Conquer(mid+1,r);
    l1=l,l2=mid+1;
    for(i=l;i<=r;i++)
    {
        if(l2>r||l1<=mid&&Compare(q[l1],q[l2]))
            nq[i]=q[l1++];
        else nq[i]=q[l2++];
    }
    memcpy(q+l,nq+l,sizeof(q[0])*(r-l+1) );
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("std.out","w",stdout); 
    int i,j,x,y,z,x1,y1,x2,y2,p;
    cin>>n;
    while(1)
    {
        scanf("%d",&p);
        if(p==1)
        {
            scanf("%d%d%d",&x,&y,&z);
            ++m,q[m]=&(mempool[m]=Query(x,y,z));
        }
        else if(p==2)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            stack[++top]=m;
            ++m,q[m]=&(mempool[m]=Query(x1-1,y1-1,-1));
            ++m,q[m]=&(mempool[m]=Query(x1-1,y2,-3));
            ++m,q[m]=&(mempool[m]=Query(x2,y1-1,-3));
            ++m,q[m]=&(mempool[m]=Query(x2,y2,-1));
        }
        else break;
    }
    sort(q+1,q+m+1,Compare);
    CDQ_Divide_And_Conquer(1,m);
    for(i=1;i<=top;i++)
    {
        int temp=0;
        for(j=1;j<=4;j++)
            temp+=ans[stack[i]+j];
        printf("%d\n",temp);
    }
    return 0;
}
