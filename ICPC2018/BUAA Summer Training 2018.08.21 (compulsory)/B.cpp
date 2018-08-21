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
#define N 600000
#define INF 99999999
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int f[N], g[N], a, b, n, tot;
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
	gets(s);
	//cout<<s<<endl;
	int len=strlen(s);
	a=read();b=read();
	s[len]=' ';
	for (int i=0;i<=len;i++)
		if (s[i]==' '){
			if (tot){
				f[++n]=tot;
				g[n]=g[n-1]+f[n];
			}
			tot=0;
		}
		else tot++;
	g[n+1]=INF;
	//cout<<n<<endl;
	for (int x=a;x<=b;x++){
		int ans=0;
		for (int j=0;j<n;){
			int le=j, ri=n+1;
			while (ri-le>1){
				int mid=le+ri>>1;
				//cout<<g[mid]-g[j]+mid-j-1<<endl;
				if (g[mid]-g[j]+mid-j-1>x)
					ri=mid;
				else
					if (g[mid]-g[j]+mid-j-1==x){
						le=mid;
						break;
					}
					else le=mid;
				//cout<<le<<' '<<ri<<endl;
			}
			//cout<<x<<' '<<j+1<<' '<<le<<' '<<g[le]-g[j]+le-j-1<<endl;
			ans+=f[j+1]+1;
			j=le;
		}
		printf("%d\n", ans-1);
	}
    return 0;
}

/*
its a long way to the top if you wanna rock n roll
13 16
*/








