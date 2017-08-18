#include <list>
#include <cstdio>
using namespace std;
int n, m, cnt,dist[20010], nu[120010], next[120010], flag[20010], p, maxx, ans;
void add(int u, int v){
    next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;
    next[++cnt]=next[v];next[v]=cnt;nu[cnt]=u;
}
int main(){
    scanf("%d%d", &n, &m);
    int u, v;
    cnt=n;
    for (int i=1;i<=m;i++) scanf("%d%d", &u, &v), add(u, v);
    for (int i=2;i<=n;i++)dist[i]=99999;
    list<int> queue;
    queue.clear();
    queue.push_back(1);
    flag[1]=1;
    while (!queue.empty()){
        int u=queue.front();
        queue.pop_front();
        int j=next[u];
        while (j){
            int v=nu[j];
            if (!flag[v]){
                dist[v]=dist[u]+1;
                queue.push_back(v);
                flag[v]=1;
            }
            j=next[j];
        }
    }
    int maxx=0, p;
    for (int i=1;i<=n;i++){
        if (dist[i]>maxx){
            maxx=dist[i];
            p=i;
            ans=0;
        }
        if (dist[i]==maxx) ans++;
    }
    printf("%d %d %d\n", p, maxx, ans);
    return 0;
}
