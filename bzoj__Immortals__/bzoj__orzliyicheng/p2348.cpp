#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int f[100200], n;
long long ans;
int cmp(int a, int b){return a<b;}
int main(){
    freopen("data.in","r",stdin);
    int j=1;
    scanf("%d", &n);
    for (int i=1;i<=n;i++) scanf("%d", &f[i]);
    sort(f+1, f+n+1, cmp);
    for (int i=2;i<=n;i++){
        while (0.9*f[i]>f[j]) j++;
        ans=ans+i-j;
    }
    cout<<ans<<endl;
    return 0;
}
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
long long ans;
int a[100005],i,L,R,mid,n,p;
int cmp(int i,int j) {return i<j;}
int main()
{
scanf("%d",&n);
for (i=1; i<=n; i++) scanf("%d",&a[i]);
sort(a+1,a+n+1,cmp);
for (i=1; i<=n; i++)
{
p=int(a[i]/0.9+0.001);
L=i; R=n; mid=(L+R)/2;
while (L<=R)
{
if (a[mid]<=p) {L=mid+1; mid=(L+R)/2;} else
{
R=mid-1;
mid=(L+R)/2;
}
}
ans+=R-i;
}
cout<<ans;
return 0;
}
