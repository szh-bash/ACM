#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int p, sum, n, ans, m;
inline bool maxn(int t, int h, int r){
    int tmp=p;
    for (int i=t;i<=m;i++){
        tmp+=h*r*r;
        h--;
        r--;
    }
    return tmp>=n;
}
inline int minn(int t, int h1, int r1){
    int h=1, r=1, tmp=p, tp2=sum;
    for (int i=t;i<m;i++){
        tmp+=h*r*r;
        tp2+=2*r*h;
        h++;
        r++;
    }
    tmp+=h1*r1*r1;
    tp2+=2*r1*h1;
    return tp2<=ans && tmp<=n;
}
void dfs(int t, int H, int R){
    if (t>m){
        ans=min(sum, ans);
        return;
    }
    for (int hi=H;hi>=m-t+1;hi--)
        if (maxn(t, hi, R))
            for (int ri=R;ri>=m-t+1;ri--){
                if (!maxn(t, hi, ri)) break;
                if (!minn(t, hi, ri)) continue;
                p+=hi*ri*ri;
                if (t==1) sum+=ri*ri;
                sum+=2*hi*ri;
                dfs(t+1, hi-1, ri-1);
                sum-=2*hi*ri;
                if (t==1) sum-=ri*ri;
                p-=hi*ri*ri;
            }
        else break;
}
int main(){
    scanf("%d%d", &n, &m);
    int tmp=n;
    for (int i=1;i<m;i++) tmp-=i*i*i;
    ans=99999999;
    dfs(1, tmp/m/m+1, 1+(int)sqrt(tmp/m));
    if (ans==99999999) ans=0;
    printf("%d", ans);
}
