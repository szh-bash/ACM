#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int T, ff[2], f[20], q[100];
char s[6][10];
int work(int u, int v, int p){
    if (ff[u]) return 0;
    ff[u]=1;
    int a, b;
    if (s[u][0]>='A') a=q[s[u][0]];else a=s[u][0]-'0';
    if (s[v][0]>='A') b=q[s[v][0]];else b=s[v][0]-'0';
    if (!p) 
        return a>=b?f[a]+work(u^1,v^1,0):-f[b]+work(u^1,v^1,1);
    else
        return a>b?f[a]:-f[b];
}
int main(){
    cin>>T;
    for (int i=1;i<=13;i++) f[i]=i;f[14]=1;
    q['A']=14;
    q['K']=13;
    q['Q']=12;
    q['J']=11;
    q['T']=10;
    while (T--){
        scanf("%s%s%s%s", s[0], s[1], s[2], s[3]);
        int ans=-9999, ans1=999, ans2=999;
        memset(ff,0,sizeof(ff));
        ans1=min(ans1,work(0,2,0));
        memset(ff,0,sizeof(ff));
        ans1=min(ans1,work(0,3,0));
        memset(ff,0,sizeof(ff));
        ans2=min(ans2,work(1,2,0));
        memset(ff,0,sizeof(ff));
        ans2=min(ans2,work(1,3,0));
        cout<<max(ans1,ans2)<<endl;
    }
    return 0;
}
