#include<cstdio>
#include<iostream>
#include<algorthim>
using namespace std;
int cmp(int a,int b){return a<b;}
int main()
{
    scanf("%d", &n);
    for (int i=1;i<=n;i++) {scanf("%d", &a[i]);sum+=a[i];}
    if (sum<=2){cout<<-1<<endl;system("pause");return 0;}
    sort(a+1,a+1+n,cmp);
    for (int i=1;i<=n;i++)
    system("pause");
    return 0;
}
