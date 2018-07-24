#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 5000
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n;
struct qlz{
	int x, y, n;
}l[N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
bool cmp(qlz a, qlz b){ return a.x<b.x;}
int main(){
	for (int T=read();T;T--){
		n=read();
		for (int i=1;i<=n*3;i++)
			l[i].x=read(),
			l[i].y=read(),
			l[i].n=i;
		sort(l+1,l+1+n*3,cmp);
		for (int i=1;i<=n;i++){
			for (int j=1;j<=3;j++)
				printf("%d ", l[i*3-j+1].n);
			printf("\n");
		}
	}
    return 0;
}
