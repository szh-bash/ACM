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
#include <tr1/unordered_map>
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
#define N 55
int n, a[N], flag[N], wf, b[N][N];
void solve(){
    n=read();
    int wf=0;
    for (int i=1;i<=n;i++) a[i]=read(), flag[i]=1, wf+=a[i]*i;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) b[i][j]=read();
    int p=0;
    for (int j=1;j<=n;j++)
        if (flag[b[wf][j]]){
            flag[b[wf][j]]=0;
            p=b[wf][j];
            break;
        }
    for (int i=n-1;i>2 && flag[wf];i--)
        for (int j=1;j<=n;j++)
            if (flag[b[p][j]]){
                flag[b[p][j]]=0;
                p=b[p][j];
                break;
            }
    if (flag[wf]) puts("langren");
    else puts("lieren");
}
int main(){
	for (int _=read();_;_--) solve();
    return 0;
}
