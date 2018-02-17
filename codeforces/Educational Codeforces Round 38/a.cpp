#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <complex>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int n;
char s[200], ans[200];
int check(char x){
	return x=='a' || x=='e' || x=='i' || x=='o' || x=='u' || x=='y'; 
}
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9')
		(ch=='-'?q=-1:0),
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	n=read();
	cin>>s;
	ans[0]=s[0];
	int cnt=0;
	for (int i=1;i<n;i++){
		if (check(s[i-1]) && check(s[i])) continue;
		ans[++cnt]=s[i];
	}
	cout<<ans<<endl;
	return 0;
}
