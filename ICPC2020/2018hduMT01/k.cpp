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
int e, flag;
char s[100];
int reads(){
    int p=0, q=1;
    while (!num(s[e]))
        (s[e++]=='-'?q=-1, flag=-1:0);
    while (num(s[e])) p=p*10+s[e++]-'0';
    return p*q;
}
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
int main(){
	for (int _=read();_;_--){
		int a=read(), b=read();
		scanf("%s", s);
		e=flag=0;
		int x=reads(), y=0;
		if (s[e]=='.') y=reads();
		if (flag<0) y=-y;
		a+=(x-8);
		b+=y*6;
		if (b<0) a--, b+=60;
		if (b>=60) a++, b-=60;
		if (a<0) a+=24;
		if (a>=24) a-=24;
		printf("%s%d:%s%d\n", a<10?"0":"",a, b<10?"0":"",b);
	}
    return 0;
}
