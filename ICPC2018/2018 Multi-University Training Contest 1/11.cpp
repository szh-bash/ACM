#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int a, b, x, p, q, flag;
char s[200];
int read(){
    int p=0;
    char ch=getchar();
    while (ch<'0' || ch>'9') ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p;
}

int reads(){
    int p=0, q=1;
    while (s[x] && (s[x]<'0' || s[x]>'9')) s[x++]=='-'?(q=-1, flag=1):0;
    while (s[x] && s[x]>='0' && s[x]<='9') p=p*10+s[x++]-'0';
    return p*q;
}
int main(){
	for (int T=read();T;T--){
		a=read();b=read();scanf("%s", s);
		x=flag=0;
		p=reads();q=reads();
		a+=p-8;
		b+=(q)*6*(flag?-1:1);
		if (b<0) b+=60, a--;
		a+=b/60;
		b%=60;
		a=(a+24)%24;
		printf("%s%d:%s%d\n", (a<10?"0":""), a, (b<10?"0":""), b);
	}
    return 0;
}
