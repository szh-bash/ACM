#include <set>
#include <ctime>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define ALPHA 62
#define mo 998244353
#define N 1000006
char s[N];
int n, a[N], g[N][ALPHA], f[N][ALPHA];
int num[ALPHA][N], nex[ALPHA][N], last[ALPHA];
int excep_all[N];
int cn2[N];
inline int dec(int a, int b){
    if (a-b<0) return a-b+mo;
    else return a-b;
}
inline int add(int a, int b){
    if (a+b>=mo) return a+b-mo;
    else return a+b;
}
inline int calc(int i, int o){
    int m=a[i];
    if (!nex[o][i] || !g[nex[o][i]][m] || !(i-num[m][i]-num[o][i])) return 0;
    return 1ll*add(dec(cn2[i-num[m][i]-num[o][i]],excep_all[i-1]),add(cn2[num[m][i-1]],cn2[num[o][i-1]]))*g[nex[o][i]][m]%mo;
}
int main(){
    scanf("%s", s+1);
    n=strlen(s+1);
    for (int i=1;i<=n;i++){
        if (s[i]>='a' && s[i]<='z') a[i]=s[i]-'a';
        else if (s[i]>='A' && s[i]<='Z') a[i]=s[i]-'A'+26;
        else a[i]=s[i]-'0'+52;
        for (int j=0;j<ALPHA;j++)
            num[j][i]=num[j][i-1];
        num[a[i]][i]++;
        nex[a[i]][last[a[i]]]=i;
        last[a[i]]=i;
        cn2[i]=1ll*i*(i-1)/2%mo;
    }
    for (int j=0;j<ALPHA;j++)
        for (int i=1;i<=n;i++){
            if (!nex[j][i] && a[i]!=j) nex[j][i]=nex[j][i-1];
            excep_all[i] = add(excep_all[i],cn2[num[j][i]]);
        }
    for (int i=n;i;i--){
        int o = a[i];
        int i_oo=nex[o][i];
        if (!i_oo) continue;
        for (int j=0;j<ALPHA;j++)
            if (j!=o && (num[j][n]-num[j][i])){
                if (num[j][i_oo]-num[j][i])
                    f[i][j] = add(f[i_oo][j],1ll*(num[j][i_oo]-num[j][i])*(num[o][n]-num[o][i])%mo);
                else f[i][j]=f[i_oo][j];
                g[i][j] = add(g[i_oo][j],f[i][j]);
            }
    }
    int ans=0;
    for (int i=3;i+3<=n;i++)
        for (int j=0;j<ALPHA;j++)
            if (j!=a[i])
                ans = add(ans,calc(i,j));
    cout<<ans<<endl;
    return 0;
}