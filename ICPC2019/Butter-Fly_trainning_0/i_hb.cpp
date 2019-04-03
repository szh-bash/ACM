#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <bitset>
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
#define BLOCK 32
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int ans[N], a[N][N], n, k;
bitset<BLOCK> c[N][N/BLOCK+5];
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
		for (int j=1,p=0,q=0;j<=n;j++){
			c[i][p][q++]=a[j][i];
			if (q==BLOCK) q=0, p++;
		}
	for (int i=1, o=1, p=0, q=0;i<=k && o<=n;o++, i++, (++q==BLOCK?q=0,++p:0)){
		if (!c[i][p][q]){
			int flag=1;
			for (int j=i+1;j<=k;j++)
				if (c[j][p][q]){
					for (int w=p;w<=(n-1)/BLOCK;w++)
						c[i][w]^=c[j][w];
					flag=0;
					break;
				}
			if (flag){
				i--;
				continue; 
			}
		}
		for (int j=i+1;j<=k;j++)
			if (c[j][p][q])
				for (int w=p;w<=(n-1)/BLOCK;w++)
					c[j][w]^=c[i][w];
	}
	for (int i=1;i<=n;i++) ans[i]=1;
	for (int i=1, o=1, p=0, q=0;i<=k && o<=n;i++){
		while (o<=n && !c[i][p][q])
			o++,
			(++q==BLOCK?q=0,++p:0);
		if (o>n) break;
		if (!ans[o]) continue;
		for (int j=o, pp=p, qq=q;j<=n;j++, (++qq==BLOCK?qq=0, ++pp:0))
			ans[j]^=c[i][pp][qq];
	}
	for (int i=1;i<=n;i++)
		if (ans[i]){
			puts("No");
			return 0;
		}
	puts("Yes");
    return 0;
}
