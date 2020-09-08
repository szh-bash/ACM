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
int main(){
	n=read();
	for (int i=1;i<=n;i++) p[i]=read();
	for (int i=1;i<=n;i++)
		if (!flag[i]){
			flag[i]=1;
			sz[++ct]=1;
			for (int j=p[i];j;j=p[j])
				if (!flag[j])
					sz[ct]++,
					flag[j]=1;
		}
//	for (int i=2;i<=
//	for (int i=1;i<=n;i++
    return 0;
}
