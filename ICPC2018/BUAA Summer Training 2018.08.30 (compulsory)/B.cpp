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
#define N 500000
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int f[N], pre[N], nex[N];
int a[N];
char s[N];
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
	while (~scanf("%s",s+1)){
		int n=strlen(s+1);
		a[n+1]=1;
		for (int i=1;i<=n;i++)
			a[i]=(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'),
			f[i]=f[i-1]+a[i],
			pre[i]=a[i]?i:pre[i-1];
		for (int i=n;i>0;i--)
			nex[i]=a[i]?i:nex[i+1];
		int i=1, j=n, o=0, ans=0;
		while (i<=j)
			if (!o){
				if (!a[i]){
					if (f[j]==f[i]) ans=1;
					break;
				}
				else{
					if (f[j]==f[i]){
						ans=j-i+1;
						break;
					}
					else{
						i++;
						j=pre[j];
						o^=1;
					}
				}
			}
			else{
				if (!a[j]){
					if (f[j]==f[i-1]) ans=1;
					break;
				}
				else{
					if (f[j-1]==f[i-1]) {
						ans=j-i+1;
						break;
					}
					else{
						i=nex[i];
						j--;
						o^=1;
					}
				}
			}
		printf("%d\n", ans);
	}
    return 0;
}
