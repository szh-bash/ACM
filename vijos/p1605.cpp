#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
int tf, n, m, f[2010], ff[2010], a[2010], a0[2010][2010], s1[2010], s2[2010];
void init(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d", &n);
    for (int i=1;i<=n;i++)
        scanf("%d", &a[i]);
    f[n+1]=999999;
    for (int i=n;i>=1;i--)
        f[i]=min(f[i+1], a[i]);
}
int flag(int x, int y){
    if (a[x]>a[y]) return 1;
    if (f[y+1]<a[x]) return 0;
    return 1;
}
void build(){
     for (int i=1;i<n;i++)
       for (int j=i+1;j<=n;j++)
         if (!flag(i,j)) a0[i][j]=a0[j][i]=1;
}
void floodfill(int t)
{
     ff[t]=1;
     for (int i=1;i<=n;i++)
     if (a0[t][i]){
         if (!ff[i]){
                    f[i]=1^f[t];
                    floodfill(i);
                    if (tf) return;
                    }
         else if ((f[i]^f[t])!=1){
                tf=1;
                return;
              }
     }
 }
void work(){
     memset(ff,0,sizeof(ff));
     memset(f,0,sizeof(f));
     tf=0;
     for (int i=1;i<=n;i++)
        if (!ff[i]) {f[i]=0;floodfill(i);if (tf) {printf("0\n");return;}}
}
void out(){
     int min=1, l1=0, l2=0, cnt=0;
     char ans[2010];
     s1[0]=s2[0]=0;
     for (int i=1;i<=n;i++){
         if (!f[i]){
                      while (s1[l1]==min){
                            l1--;min++;
                            ans[++cnt]='b';
                            }
                      s1[++l1]=a[i];
                      ans[++cnt]='a';
                      }
         else{
              while (s1[l1]==min || s2[l2]==min){
                    if (s1[l1]==min) {l1--;ans[++cnt]='b';}
                    else {l2--;ans[++cnt]='d';}
                    min++;
                    }
              s2[++l2]=a[i];
              ans[++cnt]='c';
              }
     }
     while (s1[l1]==min || s2[l2]==min){
           if (s1[l1]==min){l1--;ans[++cnt]='b';}
           else {l2--;ans[++cnt]='d';}
           min++;
           }
     for (int i=1;i<cnt;i++)printf("%c ", ans[i]);printf("%c\n", ans[cnt]);
}
int main()
{
    init();
    build();
    work();
    if (!tf) out();
    return 0;
}
