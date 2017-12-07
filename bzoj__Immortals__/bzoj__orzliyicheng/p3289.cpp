#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
struct data{
	int l, r;
}l[60000];
bool cmp(data a, data b){return a.l<b.l;}
int main(){
	scanf("%d", &n);
	for (int i=1;i<=n;i++) scanf("%d", &a[i]);
	scanf("%d", &q);
	for (int i=1;i<=q;i++) scanf("%d%d", &l[i].l, &l[i].r);
	sort(l+1,l+1+q,cmp);
	return 0;
}
