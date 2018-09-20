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
void initial(){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			for (int p=1;p<
		}
}
int main(){
	for (int _=read();_;_--){
		n=read();M=read();t=read();
		m=M>>1;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++) a[i][j]=read()%2;
		for (int i=1;i<=M;i++)
			for (int j=1;j<=M;j++) b[i][j]=read()%2;
		for (int i=1;i<=M;i++)
			for (int j=1 
	}
    return 0;
}
