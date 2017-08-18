#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a, b, f[200], x;
int main(){
	scanf("%d%d%d", &n, &a, &b);
	for (int i=1;i<=a;i++) scanf("%d", &x), f[x]=1;
	for (int i=1;i<=b;i++) scanf("%d", &x), f[x]=2;
	for (int i=1;i<=n;i++) printf("%d ", f[i]);
	return 0;
}
