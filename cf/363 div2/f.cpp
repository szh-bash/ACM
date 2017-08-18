#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, k, x[1010], y[1010], a[10], b[10], f[1010];
int main(){
    freopen("1.in","r",stdin);
    cin>>k>>n;
    for (int i=1;i<=k;i++) cin>>a[i]>>b[i];
    for (int i=1;i<=n;i++) scanf("%d%d", &x[i], &y[i]);
    for (int i=1;i<=k;i++)
        for (int j=1;j<=n;j++){
            int p1=0;
            for (int p=1;p<=n;p++){
                if (p==j) continue;
                if (x[p]<min(a[i],x[j]) || x[p]>max(a[i],x[j]))continue;
                if (y[p]<min(b[i],y[j]) || y[p]>max(b[i],y[j]))continue;
                long long f1=(long long)(y[p]-y[j])*(a[i]-x[j]), f2=(long long)(b[i]-y[j])*(x[p]-x[j]); 
                //cout<<i<<' '<<j<<' '<<p<<' '<<f1<<' '<<f2<<endl;
                if (f1==f2) {p1++;break;}
            }
            for (int p=1;p<=k;p++){
                if (p==i) continue;
                long long f1=(long long)(b[p]-y[j])*(a[i]-x[j]), f2=(long long)(b[i]-y[j])*(a[p]-x[j]); 
                if (f1==f2) p1--;
            }
            if (p1<=0) f[j]=1;
            //cout<<f[j]<<' '<<i<<' '<<j<<endl;
        }
    int ans=0;
    for (int i=1;i<=n;i++) ans+=f[i];
    cout<<ans<<endl;
    while(1);
    return 0;
}
