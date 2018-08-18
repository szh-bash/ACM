#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 6
#define M 200000
#define INF 999999999
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, len0, len[N], tail, st[N][M], p[N][M];
char s[N][M], s0[M];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void initial(int u){
    for (int i=2, j=0;i<=len[u];i++){
        while (j && s[u][j+1]!=s[u][i]) j=p[u][j];
        if (s[u][j+1]==s[u][i]) j++;
        p[u][i]=j;
    }
}
int main(){
	freopen("f.in","r",stdin);
	freopen("f.std","w",stdout);
    n=read();
    int ml=INF;
    for (int i=1;i<=n;i++){
        scanf("%s", s[i]+1);
        len[i]=strlen(s[i]+1);
        initial(i);
        ml=min(ml,len[i]);
    }
    scanf("%s", s0);
    len0=strlen(s0);
    cout<<ml<<endl;
    int tail=0;
    for (int i=0;i<len0;i++){
        if (s0[i]=='-'){
            if (tail) tail--;
        }
        else{
            for (int j=1;j<=n;j++){
                int k=st[j][tail];
                while (k && s[j][k+1]!=s0[i]) k=p[j][k];
                if (s[j][k+1]==s0[i]) k++;
                st[j][tail+1]=k;
            }
            ++tail;
        }
        int ans=INF;
        for (int j=1;j<=n;j++) ans=min(ans,len[j]-st[j][tail]);
        printf("%d\n", ans);
    }
    return 0;
}
