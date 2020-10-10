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
int f[30];
char s[200000];
int main(){
	for (int _=read(), o=1;_;_--, o++){
		scanf("%s", s);
		int ma=0;
		for (int i=0;i<26;i++) f[i]=0;
		for (int i=0;s[i];i++) f[s[i]-'a']++;
		for (int i=0;i<26;i++) ma=max(ma, f[i]);
		printf("Case #%d: %d\n", o, ma);
	}
    return 0;
}
