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
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
#define N 100005
int n;
char s[N];
unordered_map <ll, int> mp;
void solve(){
	n=read();
	scanf("%s", s);
	mp.clear();
	ll px=100000, py=100000;
	ll ans=0;
	mp[(px-1)*200005+py] = 1;
	for (int i=0;i<n;i++){
		if (s[i]=='U') py++;
		else if (s[i]=='D') py--;
		else if (s[i]=='L') px--;
		else px++;
		ans+=mp[(px-1)*200005+py];
		mp[(px-1)*200005+py] += 1;
	}
	cout<<ans<<endl;
}
int main(){
	for (int _=read();_;_--) solve();
    return 0;
}
