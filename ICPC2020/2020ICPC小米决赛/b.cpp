#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
#define num(x) (((x)>='0' && (x)<='9'))
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
using namespace std::tr1;
#define N 100005
#define M N*5
#define DATA N*15
char s[DATA];
int idx;
int read(){
    int p=0, q=1;
    while (!num(s[idx])) s[idx++]=='-'?q=-1:0;
    while (s[idx] && (num(s[idx]))) p=p*10+s[idx++]-'0';
    return p*q;
}
ull ans;
unordered_map <ll, int> mp;
int n, a[N], flag[N], lsh[M], trans[M];
ll sum[N], mx[N], lx[N], rx[N];
ll b[2][M], c[2][M];
int ct;
struct node{
    ll x;
    int pos;
}q[N];
inline ull summa(ll d[], int x){
    ll res=0;
    for (;x;x-=x&(-x)) res+=d[x];
    return res;
}
inline void upd(ll d[], int x, ll y){
    for (;x<=ct;x+=x&(-x)) d[x]+=y;
}
bool cmp(node &a, node &b){ return a.x<b.x;}
void dfs(int l, int r){
    if (l==r){
        ans+=a[l];
        return;
    }
    int mid=l+r>>1;
    dfs(l,mid);
    dfs(mid+1,r);
    int cnt=0;
    ll tmp=max(0,a[mid]);
    lsh[++cnt]=lx[mid]=mx[mid]=a[mid];
    for (int i=mid-1;i>=l;i--){
        lsh[++cnt]=lx[i]=max(lx[i+1],sum[mid]-sum[i-1]);
        lsh[++cnt]=mx[i]=max(mx[i+1],tmp+a[i]);
        tmp=max(0ll,tmp+a[i]);
    }
    for (int i=l;i<=mid;i++) q[i].x=mx[i]-lx[i], q[i].pos=i;
    sort(q+l,q+mid+1,cmp);
    ll mx_tmp=a[mid+1], rx_tmp=0; tmp=0;
    for (int i=mid+1;i<=r;i++){
        rx[i]=rx_tmp=max(rx_tmp,sum[i]-sum[mid]);
        lsh[++cnt]=mx[i]=mx_tmp=max(mx_tmp,tmp+a[i]);
        lsh[++cnt]=mx[i]-rx[i];
        tmp=max(0ll,tmp+a[i]);
    }
    sort(lsh+1,lsh+1+cnt);
    ct=0;
    for (int i=1;i<=cnt;i++) 
        if ((i==1) || lsh[i]!=lsh[i-1]) 
            trans[mp[lsh[i]]=++ct]=lsh[i];
    ull sumb=0, sumc=0, numc=0;
    for (int i=l;i<=mid;i++) 
        flag[i]=0,
        mx[i]=mp[mx[i]],
        lx[i]=mp[lx[i]],
        upd(b[0],mx[i],1), 
        upd(b[1],mx[i],trans[mx[i]]),
        sumb+=trans[mx[i]];
    for (int i=mid+1, pos=l;i<=r;i++){
        for (;pos<=mid && q[pos].x<rx[i];pos++){
            int v=q[pos].pos;
            flag[v]=1;
            upd(b[0],mx[v],-1),
            upd(b[1],mx[v],-trans[mx[v]]),
            upd(c[0],lx[v],1),
            upd(c[1],lx[v],trans[lx[v]]),
            sumb-=trans[mx[v]],
            sumc+=trans[lx[v]],
            numc++;
        }
        int x=mp[mx[i]], y=mp[mx[i]-rx[i]];
        ans+=summa(b[0],x)*mx[i]+sumb-summa(b[1],x);
        ans+=summa(c[0],y)*(mx[i]-rx[i])+sumc-summa(c[1],y)+numc*rx[i];
    }
    // for (int i=1;i<=ct;i++)
    //     b[0][i]=b[1][i]=c[0][i]=c[1][i]=0;
    for (int i=l;i<=mid;i++)
        if (!flag[i])
            upd(b[0], mx[i], -1), upd(b[1], mx[i], -trans[mx[i]]);
        else
            upd(c[0], lx[i], -1), upd(c[1], lx[i], -trans[lx[i]]);
    // mp.clear();
}
int main(){
    fread(s,1,DATA,stdin);
    n=read();
    for (int i=1;i<=n;i++) a[i]=read(), sum[i]=sum[i-1]+a[i];
    dfs(1,n);
    cout<<ans<<endl;
    return 0;
}
