#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
int l1, l2, k, f[2010][2010];
char s1[2010], s2[2010];
int main(){
    scanf("%s%s%d", s1, s2, &k);
    l1=strlen(s1);
    for (int i=l1;i>=1;i--)s1[i]=s1[i-1];
    l2=strlen(s2);
    for (int i=l2;i>=1;i--)s2[i]=s2[i-1];
    for (int i=1;i<=max(l1, l2);i++)f[i][0]=f[0][i]=k*i;
    for (int i=1;i<=l1;i++)
      for (int j=1;j<=l2;j++)
        f[i][j]=min(min(f[i-1][j],f[i][j-1])+k,f[i-1][j-1]+abs(s1[i]-s2[j]));
    cout<<f[l1][l2]<<endl;
    system("pause");
    return 0;
}
