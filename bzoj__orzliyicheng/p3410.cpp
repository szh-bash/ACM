#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<cmath>
#define maxn 50000
struct data
{int s,e;
} node[maxn+12350];
int n,ans;
int cmp(const void *a,const void *b)
{struct data *aa=(data *)a;
struct data *bb=(data *)b;if(aa->s != bb->s) return aa->s - bb->s;else return aa->e - bb->e;}
int main(){
int i,j,temp,ts,te;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d%d",&node[i].s,&node[i].e);ans=1;qsort(&node[1],n,sizeof(node[0]),cmp);te=node[1].e;for(i=1;i<=n;i++) if(node[i+1].s>=te) { ans++; te=node[i+1].e; } else if(node[i+1].e<te) { te=node[i+1].e; continue; }printf("%d\n",ans);return 0;}
