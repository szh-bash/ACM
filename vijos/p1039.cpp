#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int k, n, le, ri, a[20], ans, p1, p2, minn, f[20];
int cmp(int a, int b){return a<b;}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d", &k);
    while (k){
          k--;
          scanf("%d", &n);
          for (int i=1;i<=n;i++) scanf("%d", &a[i]);
          sort(a+1,a+1+n,cmp);
          if (n==2){
                    printf("%d\n", a[2]-a[1]);
                    continue;
                    }
          if (n%2){
                   if (!a[1]){
                              ans=a[2];
                              a[2]=0;
                              }
                   else{
                        ans=a[1];
                        }
                   le=2;ri=n;
                   while (le<ri){
                         ans=ans*10+a[le]-a[ri];
                         le++;ri--;
                         }
                   }
          else{
               memset(f,0,sizeof(f));
               for (int i=1;i<=n;i++) f[a[i]]=1;
               ans=900000;
               for (int i=2;i<=9;i++)
               if (f[i])
                 for (int j=i-1;j>=1;j--)
                   if (f[j]){
                            f[i]=f[j]=0;
                            int tp=i-j;
                            le=-1;ri=10;
                            while (le<ri){
                                 while (!f[++le]);
                                 while (!f[--ri]);
                                    if (le<ri){
                                               tp=tp*10+le-ri;
                                              }
                            }
                            f[i]=f[j]=1;
                            ans=min(ans,tp);
                            break;
                   }
               }
               printf("%d\n", ans);
    }
    return 0;
}
