#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 100010
typedef long long ll;
using namespace std;
int n, x, a[N], b[15], c[N];
char s[N*12+10];
int read(){
    int p=0;
    while (s[x]<'0' || s[x]>'9') x++;
    while (s[x]>='0' && s[x]<='9') p=p*10+s[x++]-'0';
    return p;
}
int main(){
    cin>>n;
    fread(s,1,n*12,stdin);
    for (int i=1;i<=n;i++) a[read()]=i;
    for (int i=1;i<=n;i++){
        int x=read(), le=x-4<1?1:x-4, ri=x+4>n?n:x+4, ct=0;
        for (int j=le;j<=ri;j++)
            b[++ct]=a[j];
        for (int j=1;j<ct;j++)
            for (int k=j+1;k<=ct;k++)
                if (b[j]>b[k]) swap(b[j],b[k]);
        for (int j=ct;j;j--){
            int tp=0;
            for (int k=b[j]-1;k;k-=k&(-k))
                if (c[k]>tp) tp=c[k];
            for (int k=b[j];k<=n;k+=k&(-k))
                if (tp+1>c[k]) c[k]=tp+1;
                else break;
        }
    }
    int ans=0;
    for (int j=n;j;j-=j&(-j))
        if (c[j]>ans) ans=c[j];
    cout<<ans<<endl;
    return 0;
}
