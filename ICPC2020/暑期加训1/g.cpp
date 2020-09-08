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
#define N 20
int n, m;
char a[N], b[N];
ull g[N], f[N];
int tg[N]; 
void precalc(){
	f[n-1]=a[n-1]-'0';
	g[0]=1;
	for (int i=1;i<n;i++) g[i]=g[i-1]*9;
	for (int i=n-2;i>=0;i--)
		if (f[i+1]*(a[i]-'0')>=max(a[i]-'1',(!i)*1)*g[n-i-1])
			f[i]=f[i+1]*(a[i]-'0'),
			tg[i]=0;
		else
			f[i]=max(a[i]-'1',(!i)*1)*g[n-i-1],
			tg[i]=1;
}
void print(int t){
	for (int i=t;i<n;i++)
		if (!tg[i]) printf("%c", a[i]);
		else{
			if (t || a[i]>'1') printf("%c", a[i]-1);
			for (int j=i+1;j<n;j++) printf("9");
			return;
		}
}
int main(){
	scanf("%s%s", b, a);
	n=strlen(a), m=strlen(b);
	precalc();
	if (n>m) {print(0);return 0;}
	for (int i=0;i<n;i++)
		if (a[i]==b[i]){
			printf("%c",a[i]);
			if (a[i]=='0'){
				printf("%s",a+i+1);
				break;
			}
		}
		else {
			print(i);
			break;
		}
    return 0;
}
