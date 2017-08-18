#include <cstdio>
using namespace std;
int t, n, x[10001];
int gcd(int a, int b){return b==0 ? a : gcd(b, a%b);}
int main(){
    scanf("%d", &t);
    while (t){
          scanf("%d", &n);
          for (int i=1;i<=n;i++) scanf("%d", &x[i]);
          for (int i=3;i<=n;i++){
              x[2]/=gcd(x[i],x[2]);
              if (x[2]==1) break;
          }
          x[2]/=gcd(x[1],x[2]);
          if (x[2]==1) printf("YES\n");else printf("NO\n");
          t--;
    }
    return 0;
}
