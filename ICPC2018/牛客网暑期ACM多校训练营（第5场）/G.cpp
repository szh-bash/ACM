#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef unsigned long long ull;
typedef unsigned long long ll;
using namespace std;
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
	ll c=read(), n=read();
	ll x=n/c;
	if (x<=0){
		cout<<-1<<endl;
		return 0;
	}
	if (x==1){
		cout<<c*c<<endl;
		return 0;
	}
	ll y=c*c*x*(x-1);
	cout<<y<<endl;
    return 0;
}
