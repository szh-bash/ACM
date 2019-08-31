#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
const int m=24;
int a[200];
int n, ans;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
void lu(){
	swap(a[0], a[6]); swap(a[2], a[12]);
	swap(a[6], a[16]); swap(a[12], a[18]);
	swap(a[16], a[20]); swap(a[18], a[22]);
	
	swap(a[4], a[5]);
	swap(a[5], a[11]);
	swap(a[11], a[10]);
}
void ld(){
	swap(a[16], a[20]); swap(a[18], a[22]);
	swap(a[6], a[16]); swap(a[12], a[18]);
	swap(a[0], a[6]); swap(a[2], a[12]);
	
	swap(a[11], a[10]);
	swap(a[5], a[11]);
	swap(a[4], a[5]);
}
void fc(){
	swap(a[5], a[16]); swap(a[11], a[17]);
	swap(a[16], a[14]); swap(a[17], a[8]);
	swap(a[14], a[3]); swap(a[8], a[2]);
	
	swap(a[12], a[13]);
	swap(a[13], a[7]);
	swap(a[7], a[6]);
}
void fu(){
	swap(a[14], a[3]); swap(a[8], a[2]);
	swap(a[16], a[14]); swap(a[17], a[8]);
	swap(a[5], a[16]); swap(a[11], a[17]);
	
	swap(a[7], a[6]);
	swap(a[13], a[7]);
	swap(a[12], a[13]);
}
void rt(){
	swap(a[23], a[8]); swap(a[22], a[9]);
	swap(a[8], a[6]); swap(a[9], a[7]);
	swap(a[6], a[4]); swap(a[7], a[5]);
	
	swap(a[0], a[1]);
	swap(a[1], a[3]);
	swap(a[3], a[2]);
}
void lt(){
	swap(a[6], a[4]); swap(a[7], a[5]);
	swap(a[8], a[6]); swap(a[9], a[7]);
	swap(a[23], a[8]); swap(a[22], a[9]);
	
	swap(a[3], a[2]);
	swap(a[1], a[3]);
	swap(a[0], a[1]);
}
void count(){
	int res=0;
	res+=a[0]==a[1] && a[1]==a[2] && a[2]==a[3];
	res+=a[4]==a[5] && a[5]==a[10] && a[10]==a[11];
	res+=a[6]==a[7] && a[7]==a[12] && a[12]==a[13];
	res+=a[8]==a[9] && a[9]==a[14] && a[14]==a[15];
	res+=a[16]==a[17] && a[17]==a[18] && a[18]==a[19];
	res+=a[20]==a[21] && a[21]==a[22] && a[22]==a[23];
	if (res>ans) ans=res;
}
void dfs(int n){
	count();
	if (!n) return;
	lu();
	dfs(n-1);
	ld();
	ld();
	dfs(n-1);
	lu();
	fc();
	dfs(n-1);
	fu();
	fu();
	dfs(n-1);
	fc();
	rt();
	dfs(n-1);
	lt();
	lt();
	dfs(n-1);
	rt();
}
int main(){
	while (~scanf("%d", &n)){
		for (int i=0;i<m;i++) a[i]=read();
		ans=0;
		dfs(n);
		cout<<ans<<endl;
	}
    return 0;
}
