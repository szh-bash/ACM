#include <cstdio>
#include <cstring>
using namespace std;
int exgcd(int &x, int &y, int a, int b){
	if (!b){
		x=1;
		y=0;
		return;
	}
}
int main(){
	cin>>a>>b;
	exgcd(x, y, a, b);
	cout<<x<<' '<<y<<endl;
	return 0;
}
