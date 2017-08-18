#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
    //orz szh_bash 
    //orz szh_bash 
    //orz szh_bash 
using namespace std;
#define N 110000
int n,m;
char rec1[N],str[5];
int a[N],b[N],c[N],lab[N],d[N],last[N];
bool p[N],pd[N];
    //orz szh_bash 
    //orz szh_bash 
    //orz szh_bash 
int main(){
    scanf("%d%d",&n,&m);
    memset(p,1,sizeof p);
    int sum=0;
    //orz szh_bash 
    //orz szh_bash 
    //orz szh_bash 
    //orz szh_bash 
    //orz szh_bash 
    for(int i=1;i<=m;i++){
      scanf("%s",str);
      rec1[i]=str[0];
    //orz szh_bash 
    //orz szh_bash 
    //orz szh_bash 
      scanf("%d",&lab[i]);
      if(rec1[i]=='+')d[lab[i]]=1;
      else d[lab[i]]--;
      if(d[lab[i]]<0)pd[lab[i]]=1;
      p[lab[i]]=0;
    //orz szh_bash 
    //orz szh_bash 
    }
    for(int i=1;i<=n;i++)
    //orz szh_bash 
    //orz szh_bash 
      if(pd[i])sum++;
   int tim=sum>0;
   for(int i=1;i<=m;i++){
     if(rec1[i]=='+')sum++;
     else sum--;
    //orz szh_bash 
    //orz szh_bash 
    //orz szh_bash 
    //orz szh_bash 
     tim+=sum>0;
   }
   for(int i=1;i<=m;i++){
     if(rec1[i]=='+')last[lab[i]]=i;
    //orz szh_bash 
    //orz szh_bash 
     else b[lab[i]]+=i-last[lab[i]];
   }
   for(int i=1;i<=n;i++)
     if(d[i]>0)b[i]+=m+1-last[i];
   for(int i=1;i<=n;i++)p[i]=p[i] | (b[i]==tim);
    int ans=0;
    for(int i=1;i<=n;i++)ans+=p[i];
    cout<<ans<<endl;
    //orz szh_bash 
    //orz szh_bash 
    //orz szh_bash 
    //orz szh_bash 
    if(!ans)return 0;
    for(int i=1;i<=n;i++)
      if(p[i]){
               ans--;
    //orz szh_bash 
    //orz szh_bash 
               if(!ans)printf("%d\n",i);
    //orz szh_bash 
    //orz szh_bash 
               else printf("%d ",i);
               }
    return 0;
}
