#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n, d, flag=1, dist;
char s[10];
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%d%s", &d, s);
		if (s[0]=='N'){
			if (d>dist){
				flag=0;
				break;
			}
			dist-=d;
		}
		if ((s[0]=='E' || s[0]=='W') && (!dist || dist==20000)){
			flag=0;
			break;
		}
		if (s[0]=='S'){
			if (dist+d>20000){
				flag=0;
				break;
			}
			dist+=d;
		}
	}
	if (flag && !dist) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	return 0;
}
