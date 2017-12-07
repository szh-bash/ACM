#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int f[1000001], g, x;
int main(){
    for (int i=1;i<=1000000;i++){
        int temp=i, maxx=1, minn=9;
        while (temp){
            maxx=max(maxx, temp%10);
            if (temp%10)minn=min(minn, temp%10);
            temp/=10;
        }
        f[i]=1 ^ (f[i-maxx] & f[i-minn]);
    }
    scanf("%d", &g);
    for (int i=1;i<=g;i++){
        scanf("%d", &x);
        if (f[x]) printf("YES\n");else printf("NO\n");
    }
    return 0;
}
