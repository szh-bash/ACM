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
#define INF 1000000000
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
bool work(int u, int v){
	int x, y;
	if ( ((v&1)^(u&1)) ) return 0;
		x=u/2;
		y=(u+1)/2;
		v/=2;
		x-=v;
		y+=v;
		if (x>0 && y<=INF){
			int z=y/x, p=y%x;
			if (p<z){
				cout<<y<<' '<<z<<endl;
				return 1;
			}
		}
	return 0;
}
int main(){
	/*for (int T=read();T;T--){
		int x;
		cin>>x;
		if (x==0){
			cout<<"1 1"<<endl;
			continue;
		}
		int flag=0;
		for (int i=2;i*i<=x;i++)
			if ((x/i)*i==x){
				int u=i, v=x/i;
				flag=work(u, v)||work(v, u);
				if (flag) break;
			}
		if (!flag) cout<<"-1"<<endl;
	}*/	
	for (int T=read();T;T--){
		int x, flag=0;
		cin>>x;
		for (int i=1;i<=40000;i++){
			int y=i*i-x;
			int u=sqrt(y)+0.00001;
			if (y<=0) continue;
			if (u*u==y && i/(i/u)==u){
				flag=1;
				cout<<i<<' '<<i/u<<endl;
				break;
			}
		}
		if (!flag) cout<<"-1"<<endl;
	}
	return 0;
}
