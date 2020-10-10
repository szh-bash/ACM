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
ll readll(){
    ll p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int n;
char s[200005][25];
bool cmp(char a[], char b[]){
	int n=strlen(a), m=strlen(b), c=min(n,m);
	for (int i=0;i<c;i++)
		if (a[i]<b[i]) return 1;
		else if (a[i]>b[i]) return 0;
	return n<m;
}
map<string, int> mp;
void solve(){
	n=read();
	for (int i=1;i<=n;i++) scanf("%s", s[i]), mp[s[i]]++;
	int ma=0, cnt=0, p;
	for (int i=1;i<=n;i++) ma=max(ma, mp[s[i]]);
	for (int i=1;i<=n;i++)
		if (mp[s[i]]==ma) p=i;
	
	if (ma>n-ma) cout<<s[p]<<endl;
	else cout<<"NONE"<<endl;
}
int main(){
	solve();
    return 0;
}
