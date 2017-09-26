#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a[200], tot;
map<int,int> mp;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') (ch=='-'?q=-1:0), ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		a[i]=read();
		if (!mp[a[i]]) mp[a[i]]=i, tot++;
	}
	if (tot>2 || tot==1){
		cout<<"NO"<<endl;
		return 0;
	}
	sort(a+1,a+1+n);
	if (a[n/2]==a[n/2+1]){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	cout<<a[1]<<' '<<a[n]<<endl;
	return 0;
}
