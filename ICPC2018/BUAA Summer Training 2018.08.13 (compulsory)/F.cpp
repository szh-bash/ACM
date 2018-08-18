#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 2000
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, flag[N], tag[N], a[N][N];
char s[N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void solve(int t){
//	cout<<"Round "<<t<<":"<<endl;
	int ff=0;
	for (int i=2;i<=n;i++) tag[i]=1, ff+=flag[i];
	if (!ff) return;
	for (int i=2;i<=n;i++)
		if (flag[i] && a[i][1]){
			//cout<<i<<endl;
			for (int j=2;j<=n;j++)
				if (flag[j] && a[j][i] && a[1][j] && tag[j]){
					tag[i]=tag[j]=flag[i]=0;
					printf("%d %d\n", i, j);
					break;
				}
		}
	for (int i=2;i<=n;i++)
		if (flag[i] && tag[i] && a[1][i]){
			printf("%d %d\n", 1, i);
			flag[i]=tag[i]=0;
			break;
		}
	for (int i=2;i<=n;i++)
		if (flag[i] && tag[i] && a[1][i]){
			for (int j=2;j<=n;j++)
				if (flag[j] && tag[j] && a[1][j] && i!=j){
					tag[i]=tag[j]=0;
					if (a[i][j]) flag[j]=0;else flag[i]=0;
					printf("%d %d\n", i, j);
					break;
				}
		}
	for (int i=2;i<=n;i++)
		if (flag[i] && tag[i]){
			tag[i]=0;
			for (int j=2;j<=n;j++)
				if (flag[j] && tag[j]){
					tag[j]=0;
					if (a[i][j]) flag[j]=0;else flag[i]=0;
					printf("%d %d\n", i, j);
					break;
				}
		}
	solve(t+1);
}
int main(){
	while (~scanf("%d", &n)){
		for (int i=1;i<=n;i++){
			scanf("%s", s+1);
			for (int j=1;j<=n;j++)
				a[i][j]=s[j]-'0';
		}
		for (int i=1;i<=n;i++) flag[i]=1;
		solve(1);
	}
    return 0;
}
/*
4
0110
0011
0000
1010
8
00111010
10101111
00010010
01000101
00110010
10101011
00010000
10101010
*/
