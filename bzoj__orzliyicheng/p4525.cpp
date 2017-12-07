#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n, k, x[51000];
bool check(int t){
	int tot=x[1], p=1;
	for (int i=2;i<=n;i++)
		if (tot+2*t<x[i]){
			tot=x[i];
			p++;
		}
	return p<=k;
}
int main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++) scanf("%d", &x[i]);
	sort(x+1,x+1+n);
	int le=0, ri=1000000000;
	while (le<ri-1){
		int mid=le+ri>>1;
		if (check(mid)) ri=mid;else le=mid;
	}
	cout<<ri<<endl;
	return 0;
}
