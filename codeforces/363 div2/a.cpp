#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define INF 1000000000
using namespace std;
int n, ans, b[200200];
char a[200200];
int main(){
    cin>>n;getchar();
    for (int i=1;i<=n;i++) a[i]=getchar();
    for (int i=1;i<=n;i++) scanf("%d", &b[i]);
    ans=INF;
    for (int i=2;i<=n;i++)
        if (a[i-1]=='R' && a[i]=='L')
           ans=min(ans,(b[i]-b[i-1])/2);
    if (ans==INF) cout<<-1<<endl;else cout<<ans<<endl;
    return 0;
}
