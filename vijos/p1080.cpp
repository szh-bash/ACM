#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
int a, b, c, f[30][30][30];

int dfs(int a, int b, int c){
    if (a<1 || b<1 || c<1) return 1;
    if (a>20 || b>20 || c>20) return f[20][20][20]=dfs(20, 20, 20);
    if (f[a][b][c]!=-1) return f[a][b][c];
    if (a<b && b<c) return f[a][b][c]= dfs(a, b, c-1) + dfs(a, b-1, c-1) - dfs(a, b-1, c);
    return f[a][b][c]= dfs(a-1, b, c) + dfs(a-1, b-1, c) + dfs(a-1, b, c-1) - dfs(a-1, b-1, c-1);
}

int main(){
    for (int i=0;i<=20;i++)
        for (int j=0;j<=20;j++)
            for (int k=0;k<=20;k++)
                f[i][j][k]=-1;
    f[0][0][0]=1;
    while (scanf("%d%d%d", &a, &b, &c)!=EOF){
        if (a==-1 && b==-1 && c==-1) break;
        printf("w(%d, %d, %d) = %d\n", a, b, c, dfs(a, b, c));
    }
    return 0;
}
