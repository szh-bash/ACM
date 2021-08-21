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
#include <ctime>
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
#define N 10
#define M 20
int n, m, x, a[M], b[M], e[M], r[M], flag[M*2], g[M], tag[M], p[M], q[M], c[M];
int nn, mm;
char ans[N][330000][11]; //careful data type
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int mul(int a, int b){
    if (1ll*a*b>=mo) return 1ll*a*b%mo;
    return a*b;
}
int inc(int a, int b){
    if (a+b>=mo) return a+b-mo;
    return a+b;
}
void dfs(int u){
    // cout<<n<<' '<<m<<' '<<u<<' '<<g[n-1]<<endl;
    if (u>10){
        g[n-1]++;
        for (int i=1;i<=10;i++)
            ans[n-1][g[n-1]][i]=c[i]+tag[i]*10;
        return;
    }
    int st=1;
    if (u>1 && tag[u-1]==tag[u]) st=c[u-1]+1;
    if (tag[u]){ // *
        for (int i=st;i<=m;i++)
            if (!flag[i+10])
                flag[i+10]=1,
                c[u]=i,
                dfs(u+1),
                flag[i+10]=0;
    }
    else{ // +
        for (int i=st;i<=n;i++)
            if (!flag[i])
                flag[i]=1,
                c[u]=i,
                dfs(u+1),
                flag[i]=0;
    }
}
void solve(){
    if (nn<=mm){
        int id=0;
        for (int i=1;i<=mm;i++){
            for (int j=1;j<=q[i];j++)
                tag[id+j]=1;
            if (i<=nn)
                for (int j=1;j<=p[i];j++)
                    tag[id+q[i]+j]=0;
            id+=q[i]+p[i];
        }
        dfs(1);
    }
    if (nn>=mm){
        int id=0;
        for (int i=1;i<=nn;i++){
            for (int j=1;j<=p[i];j++)
                tag[id+j]=0;
            if (i<=mm)
                for (int j=1;j<=q[i];j++)
                    tag[id+p[i]+j]=1;
            id+=q[i]+p[i];
        }
        dfs(1);
    }
}
void dfsm(int u, int res){
    if (u==mm){
        q[u]=res;
        solve();
        return;
    }
    for (int i=1;i<res;i++)
        q[u]=i,
        dfsm(u+1,res-i);
}
void dfsn(int u, int res){
    if (u==nn){
        p[u]=res;
        dfsm(1, m);
        return;
    }
    for (int i=1;i<res;i++)
        p[u]=i,
        dfsn(u+1, res-i);
}
void init(){
    for (int i=1;i<=n;i++){
        if (i-1 && i-1<=m){
            nn=i, mm=i-1;
            dfsn(1, n);
        }
        if (i<=m){
            nn=mm=i;
            dfsn(1, n);
        }
        if (i+1<=m){
            nn=i, mm=i+1;
            dfsn(1, n);
        }
    }
    cout<<n<<' '<<g[n-1]<<endl;
}
void get(){
    int anss=x;
    if (!n || !m){
        for (int i=1;i<=10;i++)
            if (b[i]) anss=mul(anss,a[i]);
            else anss=inc(anss,a[i]);
        printf("%d\n", anss);
    }
    int ct0=0, ct1=0;
    for (int i=1;i<=10;i++)
        if (b[i]) r[++ct1]=a[i];
        else e[++ct0]=a[i];
    anss=mo;
    int v=n-1, T=g[v];
	int ran=0;
	if (T>90000) ran=1;
    for (int i=1;i<=T;i+=ran?20:1){
        int res=x;
		// if (ran && 1.0*rand()/RAND_MAX>0.06) continue;
        for (int j=1;j<=10;j++){
            int y = ans[v][T-i+1][j];
            if (y>10)
                res=mul(res,r[y-10]);
            else
                res=inc(res,e[y]);
        }
        if (res<anss) anss=res;
    }
    printf("%d\n", anss);
}
int main(){
	srand(unsigned(time(NULL)));
    for (int i=1;i<10;i++)
        n=i, m=10-i,
        init();
    for (int _=read();_;_--){
        n=read(), x=read();
        m=0;
        for (int j=1;j<=n;j++){
            char op[3];
            scanf("%s", op);
            a[j]=read();
            b[j]=op[0]=='*';
            m+=b[j];
        }
        n=n-m;
        get();
    }
    return 0;
}