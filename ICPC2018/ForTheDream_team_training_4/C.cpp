#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define mo 1000000007
#define num(x) ((x)>='0' && (x)<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (!num(ch)) (ch=='-'?q=-1:0), ch=getchar();
	while (num(ch)) p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	return 0;
}
