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
char s[100];
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
	int n=read();
	map <string, int> mp;
	mp.clear();
	mp["jessie"]=1;
	for (int i=1;i<=n;i++){
		scanf("%s", s);
		int len=strlen(s);
		for (int i=0;i<len;i++) if (s[i]<'a') s[i]='a'+s[i]-'A';
		string s0=s;
		if (mp[s0]) cout<<"Good guy!"<<endl;
		else cout<<"Dare you say that again?"<<endl;
	}
    return 0;
}
