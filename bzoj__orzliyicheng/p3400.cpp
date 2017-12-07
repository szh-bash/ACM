#include <cstdio>
int p[1000], g[1000], r[2001], f;
int main(){
scanf("%d%d", &r[0], &f);
p[0]=1;
for (int i = 1; i <= r[0]; i++) scanf("%d", &r[i]), r[i] %= f;
for (int i=1; i <= r[0]; i++){
for (int j=0; j < f; j++) g[j] = p[j];
for (int j=0; j < f; j++) g[j] += p[j - r[i] + f * (j < r[i])];
for (int j=0; j < f; j++) p[j] = g[j] % 100000000;
}
p[0] = (p[0] - 1 + 100000000) % 100000000;
printf("%d\n", p[0]);
return 0;
}
