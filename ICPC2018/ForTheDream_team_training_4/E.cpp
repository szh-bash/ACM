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
int n, m, x, c[200], a[200];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	while (~scanf("%d%d%d", &m, &n, &x)){
		for (int i=1;i<=n;i++) c[i]=read(), a[i]=0;
		sort(c+1,c+1+n);
		int dis=0, incomp=0;
		for (int i=1;i<=x;i++){
			for (int j=1;j<=n;j++){
				if (a[j]<0) continue;
				a[j]++;
				if (a[j]==1){
					if (m) incomp++, m--;
					else{
						a[j]=-1;
						continue;
					}
				}
				if (a[j]==c[j]) {
					incomp--;
					a[j]=0;
				}
			}
		}
		cout<<m<<' '<<incomp<<endl;
	}
    return 0;
}
