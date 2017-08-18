#include<cstdio>
#include<cstdlib>
long long x, y, a, b;
void exgcd(long long a, long long b, long long &x, long long &y,int p)
{
     if (b==0){
               x=p;
               y=0;
               return;
               }
     exgcd(b,a%b,x,y,-p);
     long long tmp=x;
     x=y;
     y=tmp+(a/b)*y;
 }
int main()
{
    scanf("%lld%lld", &a, &b);
    exgcd(a,b,x,y,1);
    printf("%lld\n", ((x%b)+b)%b);
    system("pause");
    return 0;
}
