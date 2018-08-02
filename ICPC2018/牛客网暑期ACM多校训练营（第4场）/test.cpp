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
typedef long long ll;
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
	int ans=0, n=1000000006;
	while(ans!=1){ 
		ans=n;
		for (int i=2;i<=100000;i++){
			if (n%i==0) ans=ans/i*(i-1);
			while (n%i==0) n/=i;
		}
		if (n>1) ans=ans/n*(n-1);
		cout<<ans<<endl;
		n=ans;
	}
    return 0;
}
