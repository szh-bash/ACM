#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int n, l1, l2, a[1000], b[1000], f[1000];
int main()
{
    scanf("%d", &n);
    while (n){
          n--;
          scanf("%d", &l1);
          for (int i=1;i<=l1;i++)scanf("%d", &a[i]);
          scanf("%d", &l2);
          for (int i=1;i<=l2;i++) scanf("%d", &b[i]);
          memset(f,0,sizeof(f));
          for (int i=1;i<=l1;i++){
              int maxx=0;
              for (int j=1;j<=l2;j++)
                  if (a[i]>b[j] ) maxx=max(maxx,f[j]);
                  else
                    if (a[i]==b[j]) f[j]=max(maxx+1,f[j]);
          }
          int maxx=0;
          for (int i=1;i<=l2;i++)    
              maxx=max(maxx,f[i]);
          cout<<maxx<<endl;
    }
    system("pause");
    return 0;
}
