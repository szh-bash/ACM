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
#define N 200000
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, x, top, st[N], f[N], xi[N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	n=read();x=read();
	for (int i=1;i<=n;i++){
		int u=read(), v=read();
		if (v){
			if (top && !st[top]) top--;
			else st[++top]=v, f[top]=i, xi[top]=u;			
		}
		else{
			st[++top]=v, f[top]=i, xi[top]=u;
		}
	}
	if (top>1 && !st[top] || top==1 && !st[top] && (f[top]>1 || xi[top]>x)){
		cout<<-1<<endl;
		return 0;
	}
	if (top && st[top]==0) cout<<0<<endl;
	else cout<<top+1<<endl;
    return 0;
}










