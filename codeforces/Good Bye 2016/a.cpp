#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n, k, flag, mmin;
int main(){
	cin>>n>>k;
	mmin=240-k;
	flag=0;
	for (int i=1;i<=n;i++)
		if (mmin>=i*5){
			flag=i;
			mmin-=i*5;
		}
		else break;
	cout<<flag<<endl;
	return 0;
}
