#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
struct zsm{
    long long a, b;
    int n;
}l[50015];
int n, top, stack[50015], ans[50015];
inline bool cmp1(zsm a, zsm b){
    if (a.a<b.a) return 1;
    if (a.a>b.a) return 0;
    if (a.b<b.b) return 1;
    return 0;
}
inline bool cmp2(int a, int b){return a<b;}
inline int flag(int t){
    int v=stack[top], u=stack[top-1];
    return (l[u].b-l[v].b)*(l[t].a-l[v].a)>=(l[v].b-l[t].b)*(l[v].a-l[u].a);
}
int main(){
    scanf("%d", &n);
    for (int i=1;i<=n;i++) scanf("%lld%lld", &l[i].a, &l[i].b), l[i].n=i;
    sort(l+1,l+1+n,cmp1);
    for (int i=1;i<=n;i++){
        while ((top && l[stack[top]].a==l[i].a) || (top>1 && flag(i))) top--;
        stack[++top]=i;
    }
    for (int i=1;i<=top;i++) ans[i]=l[stack[i]].n;
    sort(ans+1,ans+1+top,cmp2);
    for (int i=1;i<=top;i++) printf("%d ", ans[i]);printf("\n");
    return 0;
}
