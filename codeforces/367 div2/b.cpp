#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int x[200000];
int main(){
	int n, m;
	cin>>n;
	for (int i=1;i<=n;i++) scanf("%d", &x[i]);
	sort(x+1,x+1+n);
	cin>>m;
	for (int i=1;i<=m;i++){
		int q;
		scanf("%d", &q);
		int le=0, ri=n+1, mid;
		while (le<ri-1){
			mid=(le+ri)/2;
			if (x[mid]<=q) le=mid;else ri=mid;
		}
		cout<<le<<endl;
	}
	return 0;
}
