#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
struct zsm{
       int x, y;
}l[6000];
int ans, w, n, ll;
int cmp1(zsm a, zsm b){return a.x<b.x;}
int cmp2(zsm a, zsm b){return a.y<b.y;}
void init()
{
     scanf("%d%d%d", &ll, &w, &n);
     for (int i=1;i<=n;i++) scanf("%d%d", &l[i].y, &l[i].x);
     l[++n].x=w;l[n].y=0;
     l[++n].x=0;l[n].y=0;
     l[++n].x=w;l[n].y=ll;
     l[++n].x=0;l[n].y=ll;
 }
void work()
{
     sort(l+1,l+1+n,cmp1);
     int low, hig;
     for (int i=1;i<=n;i++){
         low=0;hig=ll;
         for (int j=i+1;j<=n;j++){
           ans=max(ans,(hig-low)*(l[j].x-l[i].x));
           if (l[j].y>l[i].y) hig=min(l[j].y,hig);
           if (l[j].y<l[i].y) low=max(l[j].y,low);
           if (l[j].y==l[i].y) break;
         }
     }
     for (int i=n;i>=1;i--){
         low=0;hig=ll;
         for (int j=i+1;j<=n;j++){
           ans=max(ans,(hig-low)*(l[i].x-l[j].x));
           if (l[j].y>l[i].y) hig=min(l[j].y,hig);
           if (l[j].y<l[i].y) low=max(l[j].y,low);
           if (l[j].y==l[i].y) break;
         }
     }
     sort(l+1,l+1+n,cmp2);
     for (int i=1;i<=n;i++)
       ans=max(ans,w*(l[i].y-l[i-1].y));
     cout<<ans<<endl;
 }
int main()
{
    init();
    work();
    return 0;
}
