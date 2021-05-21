#include <map>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define N 200005
#define Q 200005
#define M N*2
using namespace std;
int n, q, cnt, nex[M], nu[M], g[N], mi[N], ma[N], ans[Q];
int ctt, a[Q*2+N*2], c[Q*2+N*2], f[Q*2+N*2];
unordered_map<int, int> mp;
struct node{
    int x, n;
}l[(N+Q)*2];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9') (ch=='-'?q=-1:0), ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void add(int u, int v){
    nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void addl(int x, int n){
    l[++cnt].x=x;
    l[cnt].n=n;
}
void dfs(int u){
    mi[u]=ma[u]=g[u];
    for (int j=nex[u];j;j=nex[j]){
        int v=nu[j];
        dfs(v);
        mi[u]=min(mi[u], mi[v]);
        ma[u]=max(ma[u], ma[v]);
    }
    addl(mi[u],u-n-q);
    addl(ma[u],u);
}
bool cmp(node a, node b){
    if (a.x!=b.x) return a.x<b.x;
    return a.n<b.n;
}
void upd(int x){
    for (;x<=ctt;x+=x&(-x)) c[x]++;
}
int sum(int x){
    int res=0;
    for (;x;x-=x&(-x)) res+=c[x];
    return res;
}
int main(){
    cnt=n=read();
    int ct=0;
    for (int i=1;i<=n;i++){
        int u=read(), v=read();
        a[++ct]=g[i]=read();
        if (u) add(i,u);
        if (v) add(i,v);
    }
    q=read();
    cnt=0;
    dfs(1);
    for (int i=1;i<=q;i++) {
        addl(a[++ct] = f[i] = read(), i - q);
        addl(a[++ct] = read(), i + n);
    }
    sort(l+1,l+1+cnt,cmp);
    sort(a+1,a+1+ct);
    a[0]=a[1]-1;
    for (int i=1;i<=ct;i++)
        if (a[i]!=a[i-1]) mp[a[i]]=++ctt;
    ++ctt;
    int tot=0, tot2=0;
    for (int i=1;i<=cnt;i++)
        if (l[i].n<=0) {
            if (l[i].n <= -q)
                tot++,
                tot2++;
            else
                ans[l[i].n+q]=tot,
                f[l[i].n+q+q]=tot2;
        }
        else{
            if (l[i].n <=n )
                upd(ctt-mp[mi[l[i].n]]),
                tot--;
            else {
                ans[l[i].n - n ] = (ans[l[i].n-n]+ tot2-f[l[i].n-n+q] - sum(ctt - mp[f[l[i].n-n]])) * 2 + 1;
                // cout<<i<<' '<<tot<<' '<<l[i].x<<' '<<l[i].n-n<<' '<<sum(ctt-mp[f[l[i].n-n]])<<endl;
            }
        }
    for (int i=1;i<=q;i++)
        printf("%d\n", ans[i]);
    return 0;
}
 
/*
7
2 3 4
4 0 2
5 6 8
0 0 1
0 7 5
0 0 9
0 0 6
5
2 7
0 10
2 8
4 4
3 3
 */