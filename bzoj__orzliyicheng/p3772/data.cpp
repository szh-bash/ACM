#include<set>
#include<map>
#include<ctime>
#include<queue>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define inf (9000000000000000000LL)
#define mp make_pair
#define pli pair<ll,int>
#define pii pair<int,int>
#define ll long long 
#define N 2000
#define M 500000
#define NLGN (100000*20)
using namespace std;
int read(){
	int x=0,p=1;char ch=getchar();
	while(ch<'0' || ch>'9') ch=='-'?p=-1:0, ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0', ch=getchar();
	return x*p;
}
int n, m, a[N][N];
int main(){
	freopen("data.in","w",stdout);
	srand(unsigned(time(NULL)));
	n=rand()%15+3;
//	m=max(min(rand()%6+1,n*(n-1)/2),2);
	m=rand()%(n*(n-1)/2-1)+2;
	cout<<n<<' '<<m<<endl;
	for (int i=1;i<n;i++)
		cout<<rand()%i+1<<' '<<i+1<<endl;
	for (int i=1;i<=m;i++){
		int x=rand()%n+1, y=rand()%n+1;
		while (a[x][y]) x=rand()%n+1, y=rand()%n+1;
		cout<<x<<' '<<y<<endl;
		a[x][y]=a[y][x]=1;
	}
	return 0;
}

/*
5 4
1 2
2 3
3 4
2 5
3 5
2 5
1 4
1 1
*/
