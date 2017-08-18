#include<cstdio>
#include<iostream>
using namespace std;
int q[5], cnt, n, m, nu[900000], next[900000], c[900000][5], f[900000][5];
void add(int x, int t)
{
     cnt++;
     next[cnt]=next[x];next[x]=cnt;
     nu[cnt]=t;
 }
int main()
{
    scanf("%d%d", &n, &m);
    cnt=n;
    for (int i=1;i<=m;i++){
        scanf("%d%d%d", &c[i][1], &c[i][2], &c[i][3]);
        add(c[i][1],i);
        add(c[i][2],i);
        add(c[i][3],i);
        }
    int tmp, v, j;
    for (int i=1;i<=n;i++){
        tmp=0;
        j=next[i];
        q[1]=q[2]=q[3]=0;
        while (j){
              v=nu[j];
              q[1]=max(q[1], f[v][1]);
              q[2]=max(q[2], f[v][2]);
              q[3]=max(q[3], f[v][3]);
              j=next[j];
              }
        if (!q[1]) tmp=1;
        if (!q[2]) tmp=2;
        if (!q[3]) tmp=3;
        j=next[i];
        while (j){
              v=nu[j];
              f[v][tmp]=1;
              j=next[j];
              }
        printf("%d", tmp);
        if (i==n) cout<<endl;else printf(" ");
    }
    return 0;
}
