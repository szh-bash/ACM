#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, k, q, x, y, z, x1, x2, y1, y2, c[301][301][101], a[301][301];
int lowbit(int x){return x& -x;}
void up1(int x, int y, int z){
     for (int i=x;i<=n;i+=lowbit(i))
         for (int j=y;j<=m;j+=lowbit(j)) c[i][j][z]++;
}
void up2(int x, int y, int z){
     for (int i=x;i<=n;i+=lowbit(i))
         for (int j=y;j<=m;j+=lowbit(j)) c[i][j][z]--;
}
int sum(int x, int y, int u){
    int z=0;
    for (int i=x;i;i-=lowbit(i))
        for (int j=y;j;j-=lowbit(j))
            z+=c[i][j][u];
    return z;
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i=1;i<=n;i++)
    	for (int j=1;j<=m;j++)
			scanf("%d", &a[i][j]), up1(i, j, a[i][j]);
    scanf("%d", &k);
    while (k){
    	  k--;
		  scanf("%d", &q);
          if (q==1){
                    scanf("%d%d%d", &x, &y, &z);
                    up1(x,y,z);
                    up2(x,y,a[x][y]);a[x][y]=z;
                    }
          else{
               scanf("%d%d%d%d%d", &x1, &x2, &y1, &y2, &z);
               x1--;y1--;
               int ans=sum(x2,y2, z)+sum(x1,y1,z)-sum(x2,y1,z)-sum(x1,y2,z);
               printf("%d\n", ans);
               }
    }
    return 0;
}
