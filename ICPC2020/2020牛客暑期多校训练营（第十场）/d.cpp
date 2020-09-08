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
void solve(){
	for (int i=1;i<=4;i++) a[i]=read();
	for (int i=1;i<=4;i++) b[i]=read();
	if (2*(a[1]+a[2])+a[3]+a[4]>2*(b[1]+b[2])+b[3]+b[4]){
		puts("Yes");
		return;
	}
	else if (2*(a[1]+a[2])+a[3]+a[4]==2*(b[1]+b[2])+b[3]+b[4]){
		if (a[1]+a[3]>0 && a[1]+a[2]+a[3]+a[4]>1)
			puts("Yes");
		else puts("No");
		return;
	}
	else{
		b[5]=0;
		a[5]=0;
		while (a[1]+a[3]){
			if (a[3]){
				if (b[3]){
					b[3]--;
					a[3]--;
					if (a[3]+a[4]==0) b[5]++;
					if (b[1]) b[1]--, b[3]++;
					else if (b[2]) b[2]--, b[4]++;
					else a[5]++;
				}
				else if (b[4]){
					b[4]--;
					a[3]--;
					if (b[1]) b[1]--, b[3]++;
					else if (b[2]) b[2]--, b[4]++;
					else a[5]++;
				}
				else if (b[1]){
					b[1]--;
					b[3]++;
					a[3]--;
					if (b[1]) b[1]--, b[3]++;
					else if (b[2]) b[2]--, b[4]++;
					else a[5]++;
				}
				else if (b[2]){
					b[2]--;
					b[4]++;
					a[3]--;
					if (b[1]) b[1]--, b[3]++;
					else if (b[2]) b[2]--, b[4]++;
					else a[5]++;
				}
				else{
					puts("Yes");
					return;
				}
			}
			else{
				if (b[3]){
					b[3]--;
					a[1]--; a[3]++;
					if (a[3]+a[4]==0) b[5]++;
				}
				else if (b[4]){
					b[4]--;
					a[1]--; a[3]++;
				}
				else if (b[1]){
					b[1]--; b[3]++;
					a[1]--; a[3]++;
				}
				else if (b[2]){
					b[2]--; b[4]++;
					a[1]--; a[3]++;
				}
				else{
					puts("Yes");
					return;
				}
			}
		}
		if (2*(a[1]+a[2])+a[3]+a[4]>2*(b[1]+b[2])+b[3]+b[4]){
			puts("Yes");
			return;
		}
		if (2*(a[1]+a[2])+a[3]+a[4]<2*(b[1]+b[2])+b[3]+b[4]){
			puts("No");
			return;
		}
		if (a[2]+a[4]) b[5]=0;
		if (a[5]){
			pu
		}
	}
}
int main(){
	for (int _=read();_;_--) solve();
    return 0;
}
