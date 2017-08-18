#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct zsm{
	string x;
}s[2510000];
bool cmp(zsm a, zsm b){return a.x<b.x;}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.std","w",stdout);
	int T,k,n;
	cin>>T;
	while (T--){
		cin>>k>>n;
		for (int i=1;i<=n;i++)
			cin>>s[i].x;
		sort(s+1,s+1+n,cmp);
		cout<<s[k].x<<endl;
	}
	return 0;
}
