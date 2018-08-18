#include <bits/stdc++.h>
#include<tr1/unordered_map>
#define mo 500000
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
using namespace std::tr1;

int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void dfs(int sum, int u, int q){
	if (u==n){
		
	}
	for (int i=
}
int main(){
	g[0]=1;
	while (~scanf("%d%d", &n, &k)){
		int sum=0;
		for (int i=1;i<=n;i++)
			a[i]=read(),
			sum+=a[i];
		for (int o=sum&1;sum<k;sum++, o^=1){
			dfs(sum,1,0);
		}
	}
    return 0;
}
