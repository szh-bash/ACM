#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, root, fa[300000], l[300000], cnt, a[300000];
int father(int x){return fa[x]==x?x:fa[x]=father(fa[x]);}
int main(){
   // freopen("1.in","r",stdin);
    cin>>n;
    root=cnt=0;
    for (int i=1;i<=n;i++) scanf("%d", &a[i]), fa[i]=i;
    for (int i=1;i<=n;i++)
        if (a[i]==i){root=i;break;}
    for (int i=1;i<=n;i++)
        if (father(a[i])!=father(i)) fa[fa[i]]=fa[a[i]];
        else  l[++cnt]=i;
    if (root) cout<<cnt-1<<endl;else cout<<cnt<<endl;
    if (!root) root=l[1];
    for (int i=1;i<=cnt;i++) a[l[i]]=root;
    for (int i=1;i<=n;i++) cout<<a[i]<<' ';cout<<endl;

    return 0;
}
