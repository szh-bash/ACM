#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
using namespace std;
typedef long long ll;
ll n,ans,a[5000005];
int i,j,k,l,t,m,top;
int main(){
    scanf("%lld%d",&n,&m);
    fo(i,0,m) a[i]=1;
    i=m+1;
    top=m;
    while (1){
        a[i]=a[i-1]+a[i-m];
        if (a[i]>n) break;
        top=i;
        i++;
    }
    fd(i,top,1)
        if (n>=a[i]) n-=a[i],ans+=a[i-1];
    printf("%lld\n",ans);
}
