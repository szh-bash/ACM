
#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#include <iomanip>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=500005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int head[maxn],h[maxn],in[maxn],a[maxn],dep[maxn],b[maxn];
int mfa[maxn][20],st[maxn];
ll md[maxn],dp[maxn];
bool visit[maxn]; 
int num,dfn; 
 
struct Edge {
    int from,to,pre;
    ll dist;
};
Edge edge[maxn*2],e[maxn*2];
 
void addedge(int from,int to,ll dist) {
    edge[num]=(Edge){from,to,head[from],dist};
    head[from]=num++;
    edge[num]=(Edge){to,from,head[to],dist};
    head[to]=num++;
}
 
void adde(int from,int to) {
    if (from==to) return;
    e[num]=(Edge){from,to,h[from]};
    h[from]=num++;
    e[num]=(Edge){to,from,h[to]};
    h[to]=num++;
}
 
bool cmp(int a,int b) {
    return in[a]<in[b];
}
 
void dfs(int now,ll dist,int fa,int step) { 
	mfa[now][0]=fa;
	for (int i=1;mfa[now][i-1]!=0;i++)
		mfa[now][i]=mfa[mfa[now][i-1]][i-1]; 
    visit[now]=1;  
    a[++dfn]=now;dep[now]=step;  
    in[now]=dfn; 
    if (now!=1) md[now]=min(md[fa],dist); else md[now]=llinf;
    for (int i=head[now];i!=-1;i=edge[i].pre) {  
        int to=edge[i].to;  
        if (!visit[to]) {  
            dfs(to,edge[i].dist,now,step+1);  
            a[++dfn]=now;
        }
    }  
}  
   
int findlca(int a,int b) {  
    int x=a,y=b;
    int i;
    if (dep[x]>dep[y]) swap(x,y);
    for (i=18;i>=0;i--) {
    	if (dep[mfa[y][i]]>=dep[x]) y=mfa[y][i];
    }
    if (y==x) return x;
    for (i=18;i>=0;i--) {
    	if (mfa[y][i]!=mfa[x][i]&&mfa[x][i]!=0&&mfa[y][i]!=0) {
    		x=mfa[x][i];y=mfa[y][i];
    	}
    }
    return mfa[x][0];
}
 
void makedp(int now,int fa) {
    ll sum=0;
    for (int i=h[now];i!=-1;i=e[i].pre) {
        int to=e[i].to;
        if (to!=fa) {
            makedp(to,now);
            sum+=dp[to];
        }
    }
    if (sum==0) sum=llinf;
    dp[now]=min(md[now],sum);
    h[now]=-1;
}
 
void build() {
    int n,j,i,k;
    scanf("%d",&k);
    for (i=1;i<=k;i++)
        scanf("%d",&b[i]);
    sort(b+1,b+k+1,cmp);
    num=0;
    n=1;
    for (i=2;i<=k;i++) 
        if (findlca(b[n],b[i])!=b[n]) b[++n]=b[i];
    int top=0;
    st[++top]=1;
    for (i=1;i<=n;i++) {
        int now=b[i],f=findlca(now,st[top]);
        while (true) {
            if (dep[f]>=dep[st[top-1]]) {
                adde(f,st[top--]);
                if (st[top]!=f) st[++top]=f;
                break;
            }
            adde(st[top-1],st[top]);
            top--;
        }
        if (st[top]!=now) st[++top]=now;
    }
    while (--top) adde(st[top],st[top+1]);
//    for (i=0;i<num;i++) cout << e[i].from << ' ' << e[i].to << endl;
    makedp(1,0);
    printf("%lld\n",dp[1]);
}
int main() {
	freopen("data.in","r",stdin);
	freopen("std.out","w",stdout);
    int n,i,x,y,d,q;
    scanf("%d",&n);
    num=dfn=0;memset(head,-1,sizeof(head));
    for (i=1;i<n;i++) {
        scanf("%d%d%d",&x,&y,&d);
        addedge(x,y,(ll)d);
    }
    mem0(visit);
    dfs(1,0,0,1);
    scanf("%d",&q);
    memset(h,-1,sizeof(h));
    for (i=1;i<=q;i++) 
        build();
    return 0;
}
