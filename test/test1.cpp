#include<cstdio>
int main()
{
    double ans=0;
    for (int i=1;i<=100;i++)
    {
        ans= ans+ double(1/i);
        printf("\n", ans);
    }
    scanf("%d", &ans);
}
