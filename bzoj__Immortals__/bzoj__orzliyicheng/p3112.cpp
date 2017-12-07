#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
const int MAXN=1100;
const int MAXD=11000;
const int MAXM=41000;
const int MAXINT=2000000000;
const int MININT=-2000000000;

int n,m,S,T,ansf=0,ansc=0;
int money[MAXN];
int num[MAXD],l[MAXD],r[MAXD];

int len=1;
int star[MAXN];
int et[MAXM];
int es[MAXM];
int next[MAXM];
int v[MAXM];
int c[MAXM];

int dis[MAXN];
int inq[MAXN];
int pre[MAXN];
int q[MAXN],head,tail;
//*********************************
void addedge(int qs,int qt,int qv,int qc)//qs->qt 流量qv 费用qc
{
   len++;
   es[len]=qs; et[len]=qt; v[len]=qv; c[len]=qc;
   next[len]=star[qs]; star[qs]=len;
}
void add(int qs,int qt,int qv,int qc)
{
   addedge(qs,qt,qv,qc);
   addedge(qt,qs,0,-qc);
}
int min(int aa,int bb)
{
   return aa<bb?aa:bb;
}
void init()
{
   int i,tmp;
   scanf("%d%d",&n,&m); S=n+2; T=n+3;
   for(i=1;i<=n;i++) scanf("%d",&money[i]);
   for(i=1;i<=m;i++) scanf("%d%d%d",&l[i],&r[i],&num[i]);
   for(i=1;i<=n+1;i++)
   {
       tmp=money[i]-money[i-1];
       if(tmp>0) add(i,T,tmp,0);
       if(tmp<0) add(S,i,-tmp,0);
   }

   for(i=1;i<=n;i++) add(i+1,i,MAXINT,0);

   for(i=1;i<=m;i++) add(r[i]+1,l[i],MAXINT,num[i]);

   memset(inq,0,sizeof(inq));
}
bool spfa()
{
   int i,j,ns,nt,nv,nc;

   for(i=1;i<=T;i++) dis[i]=MININT;
   head=tail=0; inq[S]=1; q[++tail]=S; pre[S]=-1; dis[S]=0;
   while(tail!=head)
   {
       ns=q[(++head)%MAXN];inq[ns]=0;
       for(j=star[ns];j;j=next[j])
       {
           nt=et[j]; nv=v[j]; nc=c[j];
           if(!nv) continue;
           if(dis[nt]>=dis[ns]+nc) continue;
           dis[nt]=dis[ns]+nc;
           pre[nt]=j;
           if(inq[nt])continue;
           inq[nt]=1;
           q[(++tail)%MAXN]=nt;
       }
   }
   return dis[T]>MININT;
}
void costflow()
{
   int j,mf=MAXINT;
   for(j=pre[T];j!=-1;j=pre[es[j]]) mf=min(mf,v[j]);
   ansf+=mf;
   for(j=pre[T];j!=-1;j=pre[es[j]])
   {
       v[j]-=mf; v[j^1]+=mf; ansc+=mf*c[j];
   }
}
int main()
{
   init();
   while(spfa()) costflow();
   printf("%d",ansc);
   return 0;
}
