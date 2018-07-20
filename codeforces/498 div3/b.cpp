#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 2000000
typedef long long ll;
using namespace std;
struct qlz{
	int x, n;
}l[N];
int n, k, ans,f[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
bool cmp(qlz a, qlz b){ return a.x>b.x;}
int main(){
	n=read();k=read();
	for (int i=1;i<=n;i++) l[i].x=read(), l[i].n=i;
	sort(l+1,l+1+n,cmp);
	for (int i=1;i<=k;i++) ans+=l[i].x, f[l[i].n]=1;
	cout<<ans<<endl;
	int j=0;
	for (int i=1;i<=n;i++){
		if (k==1){
			printf("%d\n", n-i+1);
			break;
		}
		j++;
		if (f[i]){
			printf("%d ", j);
			j=0;
			k--;
		}
	}
	return 0;
}
