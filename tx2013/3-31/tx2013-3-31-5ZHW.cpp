#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m,i,a[100005],t[200005],o,MAX,j;
long long ans;
bool flag;
struct node {int x;int y;};
node b[100005];
int cmp(int i,int j) {return i<j;}
int cmd(node i,node j) {return i.x<j.x;}
int cml(int i,int j) {return i>j;}
int main()
{
    n=0; m=0;
    cin>>n>>m;
    while (n!=0 || m!=0)
    {
          flag=true;
          for (i=1; i<=n; i++) scanf("%d",&a[i]);
          //da dsfasdfdasfdsads
          sort(a+1,a+n+1,cmp);
                    //da dsfasdfdasfdsads
          for (i=1; i<=m; i++) scanf("%d",&b[i].x);
          for (i=1; i<=m; i++) scanf("%d",&b[i].y);/*
          dfa fdask fhqew hfksch
          d hfasdh kjdash jkdhas
          dsakj jdas
          */
          sort(a+1,a+n+1,cmp);
                    //da dsfasdfdasfdsads
          sort(b+1,b+m+1,cmd);
          o=0;
          j=m; 
          ans=0;
          for (i=n; i>=1; i--)
          {
                        //da dsfasdfdasfdsads
              MAX=453266144;
              while (b[j].x>=a[i]) 
              {
                    if (b[j].y<MAX)
                    {
                                   if (MAX!=453266144)
                                   {
                                                       t[++o]=MAX;
                                                       push_heap(t+1,t+o+1,cml);
                                   }
                                   MAX=b[j].y;
                    }
                    else          //da dsfasdfdasfdsads
                    {
                        o++;
                        t[o]=b[j].y;/*dsakfj kldasj fkl
                        dsafk jasdkfj das
                        ajsdklfhakifqew
                        jaskfhqewfjew
                        */
                        push_heap(t+1,t+o+1,cml);
                    }
                    j--;
              }
              if (MAX==453266144 && o==0) {cout<<"No"<<endl; flag=false; break;}
              if (t[1]<MAX && o!=0) {ans+=t[1]; pop_heap(t+1,t+o+1,cml);o--;if (MAX!=453266144){ t[++o]=MAX; push_heap(t+1,t+o+1,cml);}}
              else ans+=MAX;          //da dsfasdfdasfdsads
          }        
          if (flag) cout<<ans<<endl; 
          n=0; m=0;
          cin>>n>>m;
    }
    return 0;
}     