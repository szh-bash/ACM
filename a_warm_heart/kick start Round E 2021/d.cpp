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
const double EulerConstant = 0.5772156649;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
ll n;
void solve(int o){
	cin>>n;
	double ans;
	if (n<=1000000){
		ans=0;
		for (int i=1;i<=n;i++)
			ans+=1.0/i;
		printf("Case #%d: %.8lf\n", o, ans);
		return;
	}
	ans=log(n+1)+EulerConstant;
	printf("Case #%d: %.8lf\n", o, ans);
}
// 14.39272672
int main(){
	for (int _=read(), o=1;_;_--, o++) solve(o);
    return 0;
}
