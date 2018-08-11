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
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, tag[100], g[1005][1005], q[1005], w[1005];
ll ans;
short a[1005][1005];
char s[1005];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
bool check(int l1, int r1, int l2, int r2){
	for (int i=l1;i<=l2;i++){
		for (int j=1;j<=52;j++) tag[j]=0;
		for (int j=r1;j<=r2;j++)
			if (tag[a[i][j]]) return 0;
			else tag[a[i][j]]=1;
	}
	for (int j=r1;j<=r2;j++){
		for (int i=1;i<=52;i++) tag[i]=0;
		for (int i=l1;i<=l2;i++)
			if (tag[a[i][j]]) return 0;
			else tag[a[i][j]]=1;
	}
	return 1;
}
int main(){
	freopen("j.in","w",stdout);
	srand(unsigned(time(NULL)));
	n=30;m=30;
	cout<<n<<' '<<m<<endl;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			int x=rand()%2, y=rand()%13;
			//int x=1, y=rand()%3;
			cout<<(char)('A'+y+x*32);
		}
		cout<<endl;
	}
	return 0;
}
