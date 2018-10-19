#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int read(){
    int p=0, q=-1;
    char ch=getchar();
    while (!num(ch)) (ch=='-'?q=-1:0), ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void add(int u, int v, int w){
    nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void dfs(int u, int dep){
}
}
void initialize(){
    dfs(1,0);
}
void solve(){

}
int main(){
    cnt=n=read();
    for (int i=1;i<n;i++){
        int u=read(), v=read(), w=read();
        add(u,v,w);
    }
    initialize();
    for (int _=read();_;_--)
        solve();
    return 0;
}
