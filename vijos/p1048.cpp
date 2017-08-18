//I love zsm!
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct zsm{
       int v, n;
       }l[200];
int n, cnt, f[200], next[3000], nu[3000], p=0, ans=0, sum=0, a[200], b[200];
void add(int u, int v){
     next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;
}
int cmp(zsm a, zsm b){return a.v>b.v;}
int flag(int t){
	if (f[t]) return 0;
	int j=next[t];
	while (j){
		if (!f[nu[j]]) return 0;
		j=next[j];
	}
	return 1;
}
void dfs(int i){
     if (i>n) {ans=max(ans,p);return;}
     if (sum+p<=ans) return;
     if (!f[i]){
                    int j=next[i];
                    while(j){
                             if (!f[nu[j]]) sum-=a[nu[j]];
                             f[nu[j]]++;
                             j=next[j];
							 }
                    f[i]=1;
                    p+=a[i];
                    sum-=a[i];
                    dfs(i+1);
                    f[i]=0;
                    p-=a[i];
                    sum+=a[i];
                    j=next[i];
                    while (j){
                          f[nu[j]]--;
                          if (!f[nu[j]]) sum+=a[nu[j]];
                          j=next[j];
                          }
                    }
     if (!flag(i))dfs(i+1);
}
int main(){

    scanf("%d", &n);
    for (int i=1;i<=n;i++) scanf("%d", &l[i].v), sum=sum+l[i].v, l[i].n=i;
    sort(l+1,l+1+n,cmp);
    for (int i=1;i<=n;i++) a[i]=l[i].v, b[l[i].n]=i;
    int u, v;
    cnt=n;
    while (scanf("%d%d", &u, &v)!=EOF) add(min(b[u],b[v]), max(b[u],b[v]));
    memset(f,0,sizeof(f));
    dfs(1);
    printf("%d\n", ans);
    return 0;
}
