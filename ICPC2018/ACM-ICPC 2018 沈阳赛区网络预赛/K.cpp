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
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int a[]={1,2,3,5,7};
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void dfs(int t, int p){
	if (t>1 && check(p)) ans[++cnt]=p;
	for (int i=0;i<5;i++)
		if (b[i] && 
}
int main(){
	for (int i=2;i<N;i++)
		if (!flag[i]){
			zs[++cnt]=i;
			for (int j=2;j*i<N;j++)
				flag[i*j]=1;
		}
	dfs(1, 0);
	for (int _=read();_;_--){
		
	}
    return 0;
}
