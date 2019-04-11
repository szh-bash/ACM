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
typedef long long ll;
using namespace std;
int n, m, h[5000], b[50000];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
bool check(int x){
	for (int i=1;i<=x;i++) b[i]=h[i];
	sort(b+1,b+1+x);
	int tot=0;
	for (int i=x;i>0;i-=2){
		tot+=b[i];
		if (tot>m) return 0;
	}
	return 1;
}
int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) h[i]=read(); 
	int le=1, ri=n+1;
	while (le<ri-1){
		int mid=le+ri>>1;
		if (check(mid)) le=mid;else ri=mid;
	}
	cout<<le<<endl;
	return 0;
}
