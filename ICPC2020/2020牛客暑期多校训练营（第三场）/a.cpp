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
char s[2000005];
void solve(){
	int n=read();
	scanf("%s", s+1);
	int fs=0, tools=0;
	for (int i=1;i<=n;i++)
		if (s[i]=='0'){
			if (tools) tools--, fs++; 
		}
		else if (s[i]=='1'){
			tools++;
		}
		else if (s[i]=='2'){
			fs++;
		}
		else{
			fs++;
		}
	if (tools) fs+=tools/2;
	printf("%d\n", fs);
}
int main(){
	for (int _=read();_;_--) solve();
    return 0;
}
