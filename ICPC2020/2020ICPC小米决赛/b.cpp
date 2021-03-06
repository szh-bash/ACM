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
#define num(x) (((x)>='0' && (x)<='9'))
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
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
int n, a[N], flag[N], loc[N];
ll sum[N], mx[N], lx[N], rx[N];
struct node{
    ll x;
    int pos;
}q[N], p[N];
bool cmp(node &a, node &b){ return a.x<b.x;}
void dfs(int l, int r){
    if (l==r){
        ans+=a[l];
        return;
    }
    int mid=(l+r)>>1;
    dfs(l,mid);
    dfs(mid+1,r);
    ll tmp=max(0,a[mid]);
    lx[mid]=mx[mid]=a[mid];
    for (int i=mid-1;i>=l;i--){
        lx[i]=max(lx[i+1],sum[mid]-sum[i-1]);
        mx[i]=max(mx[i+1],tmp+a[i]);
        tmp=max(0ll,tmp+a[i]);
    }
    for (int i=l;i<=mid;i++) 
        q[i].x=mx[i]-lx[i], q[i].pos=i,
        p[i].x=mx[i], p[i].pos=i;
    sort(q+l,q+mid+1,cmp);
    sort(p+l,p+mid+1,cmp);
    for (int i=l;i<=mid;i++) loc[p[i].pos]=i;
    ll mx_tmp=a[mid+1], rx_tmp=0;
    tmp=0;
    for (int i=mid+1;i<=r;i++){
        rx[i]=rx_tmp=max(rx_tmp,sum[i]-sum[mid]);
        mx[i]=mx_tmp=max(mx_tmp,tmp+a[i]);
        tmp=max(0ll,tmp+a[i]);
    }
    ull sumb=0, sumc=0, numbl=0, sumbl=0, numcl=0, sumcl=0, numc=0;
    for (int i=l;i<=mid;i++) 
        flag[i]=0,
        sumb+=mx[i];
    for (int i=mid+1, pos=l, pos_p=l, pos_t=mid;i<=r;i++){
        for (;pos<=mid && q[pos].x<rx[i];pos++){
            int v=q[pos].pos;
            flag[v]=1;
            if (loc[v]<pos_p) sumbl-=mx[v], numbl--;
            sumb-=mx[v];
            sumc+=lx[v];
            numc++;
            if (v>pos_t) sumcl+=lx[v], numcl++;
        }
        for (;pos_p<=mid && p[pos_p].x<mx[i];pos_p++){
            int v=p[pos_p].pos;
            numbl+=flag[v]^1;
            sumbl+=(flag[v]^1)*mx[v];
        }
        for (;pos_t>=l && lx[pos_t]<mx[i]-rx[i];pos_t--){
            numcl+=flag[pos_t];
            sumcl+=flag[pos_t]*lx[pos_t];
        }
        ans+=sumb-sumbl+numbl*mx[i];
        ans+=numcl*mx[i]+sumc-sumcl+(numc-numcl)*rx[i];
    }
}
int main(){
    fread(s,1,DATA,stdin);
    n=read();
    for (int i=1;i<=n;i++) a[i]=read(), sum[i]=sum[i-1]+a[i];
    dfs(1,n);
    cout<<ans<<endl;
    return 0;
}
