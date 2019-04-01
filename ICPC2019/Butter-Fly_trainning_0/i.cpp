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
#include <tr1/unordered_map>
#define N 2000
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int ans[N], a[N][N], b[N][N], n, k;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	n=read();k=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=k;j++) a[i][j]=(read()%2+2)%2;
	for (int i=1;i<=k;i++)
		for (int j=1;j<=n;j++) b[i][j]=a[j][i];
	for (int i=1, o=1;i<=k && o<=n;o++, i++){
		if (!b[i][o]){
			int flag=1;
			for (int j=i+1;j<=k;j++)
				if (b[j][o]){
					for (int p=o;p<=n;p++)
						b[i][p]^=b[j][p];
					flag=0;
					break;
				}
			if (flag){
				i--;
				continue;
			}
		}
		for (int j=i+1;j<=k;j++)
			if (b[j][o])
				for (int p=o;p<=n;p++)
					b[j][p]^=b[i][p];
	}
	for (int i=1;i<=n;i++) ans[i]=1;
	for (int i=1, o=1;i<=k && o<=n;i++){
		while (o<=n && !b[i][o]) o++;
		if (o>n) break;
		for (int j=o+1;j<=n;j++)
			ans[j]^=b[i][j]&ans[o];
		if (ans[o]) ans[o]^=1;
	}
	for (int i=1;i<=n;i++)
		if (ans[i]){
			puts("No");
			return 0;
		}
	puts("Yes");
    return 0;
}
