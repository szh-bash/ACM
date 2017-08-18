#include<cstdio>
#include<iostream>
using namespace std;
int n, x, y, c[400];
int main()
{
    scanf("%d", &n);
    int sum=0, p=0;
    for (int i=1;i<=n;i++){scanf("%d", &c[i]);sum+=c[i];}
    scanf("%d%d", &x, &y);
    for (int i=1;i<=n;i++)
        {
             p+=c[i];
             if (p>=x && p<=y && sum-p<=y && sum-p>=x){printf("%d\n", i+1);return 0;}
         }
    printf("%d\n", 0);
    return 0;
}
