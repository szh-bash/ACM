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
int a[200][200], b[200][200], flag[200], n, ans;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
bool check(){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			b[i][j]=a[i][j];
	int cnt=n;
	while (cnt<n*n){
		int flag=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (!b[i][j] && b[i-1][j]+b[i][j-1]+b[i+1][j]+b[i][j+1]>1) b[i][j]=1, cnt++, flag=1;
		if (!flag) break;
	}
	if (cnt<n*n){
		//cout<<n<<": "<<ans<<endl;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++)
				cout<<a[i][j];
			cout<<endl;
		}
		cout<<endl;
	}
	return cnt==n*n;
}
void dfs(int t){
	if (t>n){
		if (check()) ans++;
		return ;
	}
	for (int i=1;i<=n;i++)
		if (!flag[i]){
			a[t][i]=1;
			flag[i]=1;
			dfs(t+1);
			flag[i]=0;
			a[t][i]=0;
		}
}
int main(){
	freopen("b_invalid.txt","w",stdout);
	for (n=1;n;n++){
		ans=0;
		dfs(1);
		cout<<n<<' '<<ans<<endl;
	}
    return 0;
}
