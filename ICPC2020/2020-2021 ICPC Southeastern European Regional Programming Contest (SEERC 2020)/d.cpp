#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define N 1005
int n, a[4][N], loc[N][4][2], cot[N], ept, ept2;
int ans, st[6*N], ed[6*N];
int read(){
    int p=0;
    char ch=getchar();
    while (ch<'0' || ch>'9') ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p;
}
bool check(int x){
    int v=a[1][x];
    if (!v) return 1;
    for (int j=2;j<=3;j++)
        if (loc[v][j][1]!=loc[v][j-1][1])
            return 0;
    // cout<<x<<' '<<v<<endl;
    return 1;
}
void mov(int fr_x, int fr_y, int to_x, int to_y){
    int v=a[fr_x][fr_y];
    for (int j=1;j<=3;j++)
        if (loc[v][j][0]==fr_x && loc[v][j][1]==fr_y){
            loc[v][j][0]=to_x;
            loc[v][j][1]=to_y;
            a[fr_x][fr_y]=0;
            a[to_x][to_y]=v;
            break;
        }
}
void add_ans(int fr, int to, int to2=0){
    if (a[1][to]) to=to2;
    ++ans;
    st[ans]=fr;
    ed[ans]=to;
    for (int i=1;i<=3;i++)
        if (a[i][fr]){
            for (int j=3;j;j--)
                if (!a[j][to]){
                    mov(i,fr,j,to);
                    break;
                }
            break;
        }
}
void pick_last(int fr_x, int fr_y, int to){
    if (ept==fr_y) swap(ept,ept2);
    for (int i=1;i<fr_x;i++)
        if (a[i][fr_y])
            add_ans(fr_y,ept,ept2);
    add_ans(fr_y,to);
    if (!a[2][ept] && ept!=fr_y)
        add_ans(ept,fr_y),
        ept2=ept;
    else{
        for (int i=fr_x+1;i<=3;i++)
            add_ans(fr_y,ept,ept2);
        ept=ept2=fr_y;
    }
}
void set(int x){
    int v = a[1][x];
    // for (int i=1;i<=3;i++)
    //     for (int j=i+1;j<=3;j++)
    //         if (loc[v][i][0]>loc[v][j][0])
    //             swap(loc[v][i], loc[v][j]);
    for (int j=1;j<=3;j++)
        if (loc[v][j][1]!=x){
            int dep = loc[v][j][0];
            int col = loc[v][j][1];
            int tgx;
            if (dep==3){
                add_ans(col,ept);
                add_ans(col,ept);
                add_ans(x,col);
                tgx=col;
                ept2=x;
            }
            else if (dep==2){
                add_ans(x,ept);
                add_ans(col,x);
                add_ans(col,ept);
                tgx=ept;
                ept=ept2=col;
            }
            else{
                add_ans(x,ept);
                add_ans(col,ept);
                // add_ans(col,x);
                tgx=ept;
                ept=x;
                ept2=col;
                // ept=ept2=col;
            }
            for (int k=1;k<=3;k++)
                if (loc[v][k][1]!=tgx){
                    pick_last(loc[v][k][0],loc[v][k][1],tgx);
                    break;
                }
            // cout<<ans<<endl;
            break;
        }

}
int main(){
    n=read();
    ept=n+1;
    for (int i=1;i<=3;i++)
        for (int j=1;j<=n;j++){
            int v=a[i][j]=read();
            cot[v]++;
            loc[v][cot[v]][0]=i;
            loc[v][cot[v]][1]=j;
            // cout<<i<<' '<<j<<' '<<a[i][j]<<' '<<cot[v]<<' '<<loc[v][cot[v]][0]<<' '<<loc[v][cot[v]][1]<<endl;
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n+1;j++)
            if (!check(j)){
                // cout<<i<<' '<<j<<endl;
                set(j);
                break;
            }
    if (ept!=n+1)
        for (int i=1;i<=3;i++)
            add_ans(n+1,ept);
    cout<<ans<<endl;
    for (int i=1;i<=ans;i++)
        printf("%d %d\n", st[i], ed[i]);
    return 0;
}

/*
3
1 1 1
2 3 2
2 3 3
*/