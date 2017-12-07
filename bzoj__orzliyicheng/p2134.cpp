#include <cstdio>
#include <iostream>
using namespace std;
double ans;
int n, A, B, C, a[10000010];
int main(){
scanf("%d%d%d%d%d",&n,&A,&B,&C,a+1); 
for (int i=2;i<=n;i++) a[i] = ((long long)a[i-1] * A + B) % 100000001; 
for (int i=1;i<=n;i++) a[i] = a[i] % C + 1; a[0]=a[n];
for (int i=1;i<=n;i++) ans += (double)1/max(a[i],a[i-1]);
printf("%.3f", ans);
system("pause");
return 0;
}
