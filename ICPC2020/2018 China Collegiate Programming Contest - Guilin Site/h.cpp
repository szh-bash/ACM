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
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
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
int power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
#define N 10005
char s0[N], s1[N], ans[N];
void solve(int T){
	scanf("%s", s0);
	scanf("%s", s1);
	int n=strlen(s0), p=0, q=0;
	for (int i=0;i<n;i++){
		if (s0[i]!='a' || s1[i]!='a')
			p+=s0[i]!='a',
			q+=s1[i]!='a';
		ans[i]='a';
	}
	if (p<q) swap(p, q), swap(s0, s1);
	int del = p - q;
	for (int i=n-1;i>=0, del;i--){
		if (s0[i]==s1[i]) continue;
		if (s0[i]!='a' && s1[i]!='a'){
			del--,
			ans[i]=s0[i];
			continue;
		}
		if (s0[i]=='a') continue;
		if (del>1){
			del-=2,
			ans[i]=s0[i];
		}
		else{
			if (s0[i]=='b') ans[i]='c';
			else ans[i]='b';
			del--;
		}
	}
	ans[n]='\0';
	printf("Case %d: %s\n", T, ans);
}
int main(){
	for (int _=read(), o=1;_;_--, o++) solve(o);
    return 0;
}
