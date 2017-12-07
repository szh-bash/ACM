#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define re(i,n) for(int i=0;i<n;i++)
#define db(x) cout<<#x<<"="<<(x)<<" "
#define el cout<<endl
using namespace std;
const int MXN=10000009;
int N=10000000,M,Q;
int mp[MXN];
void init(){
scanf("%d %d",&M,&Q);
int x;
rep(im,1,M){
scanf("%d",&x);
if (!mp[x])
for(int i=0;i<=N;i+=x) mp[i]=max(mp[i],x);
}
}
namespace solve{
int lim=~0U>>2;
int q[MXN],top;
int dis[MXN];
void solve(){
q[top=0]=0;
int mx=0;
rep(i,0,N){
if (i>q[top]){
lim=i;
break;
}
dis[i]=top;
mx=max(mx,i+mp[i]-1);
if (i==q[top]){
q[++top]=mx;
}
}
int x;
rep(iq,1,Q){
scanf("%d",&x); 
if (x<lim) printf("%d\n",dis[x]);
else printf("oo\n");
}
}
}
int main(){
init();
solve::solve();
return 0;
}

