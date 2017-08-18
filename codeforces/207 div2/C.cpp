#include<cstdio>
#include<iostream>
using namespace std;
int flag, n, m, f[3000000], p[4000000], ans, li, ri, xi, nex[4000000], pre[4000000];
void build(int t,int l,int r)
{
     f[t]=r-l+1;
     if (l==r) return;
     int mid=(l+r)/2;
     build(t*2,l,mid);
     build(t*2+1,mid+1,r);
 }
void work(int t,int l,int r)
{
     if (l==r) {flag=1;ans=l;return;}
     int mid=(l+r)/2;
     if (f[t*2]) work(t*2,l,mid);
     else 
       if (f[t*2+1])work(t*2+1,mid+1,r);
 }
void query(int t, int l, int r)
{
    if (li<=l && r<=ri) {work(t,l,r);return;}
    int mid=(l+r)/2;
    if (li<=mid) query(t*2,l,mid);
    if (flag) return;
    if (mid<ri) query(t*2+1,mid+1,r);
}
void update(int t, int l, int r)
{
     if (l==r) {f[t]=0;return;}
     int mid=(l+r)/2;
     if (ans<=mid) update(t*2,l,mid);else update(t*2+1,mid+1,r);
     f[t]=f[t*2]+f[t*2+1];
}
int main()
{
    scanf("%d%d", &n, &m);
    build(1,1,n);
    for (int i=1;i<=n;i++) {nex[i]=i+1;pre[i]=i-1;}
    for (int i=1;i<=m;i++){
        scanf("%d%d%d", &li,&ri,&xi);
        flag=0;
        query(1,1,n);
        while (ans<=ri){
              if (ans!=xi){
                           p[ans]=xi;
                           update(1,1,n);
                           pre[nex[ans]]=pre[ans];
                           nex[pre[ans]]=nex[ans];
                           }
              ans=nex[ans];
              }
    }
    for (int i=1;i<n;i++) printf("%d ", p[i]);
    printf("%d\n", p[n]);
    return 0;
}
