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
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int n, m=1, ans, k, a[200];
struct pa{
	int x, u, v;
}l[100];
int check(int x){
	int ct=0;
	while (x){
		a[++ct]=x%3;
		x/=3;
	}
	for (int i=1;i<=k;i++)
		if (l[i].x!=(a[l[i].u]==a[l[i].v])) return 0;
	return 1;
}
char op[5];
int main(){
	n=read();k=read();
	for (int i=1;i<=k;i++){
		int u, v;
		scanf("%s%d%d", op, &l[i].u, &l[i].v);
		l[i].x=op[0]=='S';
	}
	for (int i=1;i<=n;i++) m*=3;
	for (int i=0;i<m;i++) ans+=check(i);
	cout<<ans<<endl;
    return 0;
}

