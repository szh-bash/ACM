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
#define N 3000
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, bl, ans[N][N];
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
int main(){
	bl = 3;
	n = bl*bl;
	for (int i=0;i<bl;i++){
		for (int p=0;p<bl;p++){
			int stx = i*bl, sty = p*bl;
			cout<<stx<<' '<<sty<<endl;
			for (int j=1;j<=bl;j++)
					ans[stx+j][sty+(j-i+p-1)%bl+1]=1;			
		}
	}
	int tot=0;
	cout<<n<<endl;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
			printf("%d",ans[i][j]),
			tot++;
		puts("");
	}
	cout<<tot<<endl;
    return 0;
}
