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
#define N 400000
typedef long long ll;
using namespace std;
int n, x, y, fx[N], fy[N];
char s[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	n=read();
	scanf("%s", s);
	x=read();y=read();
	if (abs(x)+abs(y)>n || (n-abs(x)-abs(y))&1){
		cout<<-1<<endl;
		return 0;
	}
	for (int i=0;i<n;i++){
		fx[i+1]=fx[i];
		fy[i+1]=fy[i];
		if (s[i]=='U') fy[i+1]++;
		if (s[i]=='R') fx[i+1]++;
		if (s[i]=='D') fy[i+1]--;
		if (s[i]=='L') fx[i+1]--;
	}
	int ans=N;
	for (int i=0;i<=n;i++){
		int le=i-1, ri=n+1, flag=0;
		while (le<ri-1){
			int mid=le+ri>>1;
			int curx=fx[i]+fx[n]-fx[mid];
			int cury=fy[i]+fy[n]-fy[mid];
			if (abs(curx-x)+abs(cury-y)<=mid-i) ri=mid, flag=1;
			else le=mid;
		}
		if (flag) ans=min(ans,ri-i);
	}
	cout<<ans<<endl;
	return 0;
}
