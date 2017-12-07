#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int f[1000001], fa[1000001], l[1000001], r[1000001], key[1000001], c[1000001], a, b, n, m;
int father(int x){return x==fa[x] ? x : fa[x] = father(fa[x]);}
int merge(int a, int b){
     if (!a || !b) return a+b; 
     if (c[a]>c[b]) swap(a, b);
     if (key[l[a]]<key[r[a]]) swap(l[a], r[a]);
     r[a]=merge(r[a], b);
     key[a]=min(key[l[a]], key[r[a]])+1;
     return a;
}
int main(){
    freopen("input.in","r",stdin);
    scanf("%d", &n);
    for (int i=1;i<=n;i++) scanf("%d", &c[i]), fa[i]=i, key[i]=1;
    scanf("%d", &m);
    for (int i=1;i<=m;i++){
        char  ch;
        getchar();
        scanf("%c", &ch);
        if (ch=='M'){
           scanf("%d%d", &a, &b);
           if (f[a] || f[b]) continue;
           a=father(a);
           b=father(b);
           if (a==b) continue;
           fa[a]=fa[b]=merge(a, b);
        }
        else{
             scanf("%d", &a);
             if (f[a]){
                        printf("0\n");
                        continue;
             }
             a=father(a);
             printf("%d\n", c[a]);
             f[a]=1;
             fa[a]=merge(l[a], r[a]);
             fa[fa[a]]=fa[a];
        }
    }
    return 0;
}
