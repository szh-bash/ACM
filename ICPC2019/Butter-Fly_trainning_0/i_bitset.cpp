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
#define N 1501
#define num(x) (x>='0' && x<='9')
using namespace std;
int a[N][N], n, k;
bitset<1501> c[N], ans;
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
		for (int j=1;j<=k;j++) 
			if (read()&1) c[j].set(i);
	ans.set();
	for (int i=1, o=1;i<=k && o<=n;o++, i++){
		if (!c[i][o]){
			int flag=1;
			for (int j=i+1;j<=k;j++)
				if (c[j][o]){
					c[i]=c[i]^c[j];
					flag=0;
					break;
				}
			if (flag){
				i--;
				continue;
			}
		}
		if (ans[o]) ans=ans^c[i]; 
		for (int j=i+1;j<=k;j++)
			if (c[j][o]) c[j]=c[j]^c[i];
	}
	for (int i=1;i<=n;i++)
		if (ans[i]){
			puts("No");
			return 0;
		}
	puts("Yes");
    return 0;
}
