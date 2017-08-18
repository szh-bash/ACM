#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
int n, k, a[60][60];
int main(){
    scanf("%d", &n, &k);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) scanf("%d", &a[i][j]);
    return 0;
}
