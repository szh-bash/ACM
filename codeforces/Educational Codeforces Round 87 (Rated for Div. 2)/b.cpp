#include <map>
#include <set> 
#include <ctime>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
ll readll(){
	ll p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
char s[300000];
int g[3];
int main(){
	for (int _=read();_;_--){
		scanf("%s", s);
		int j=0, ans=300000;
		g[0]=g[1]=g[2]=0;
		for (int i=0;s[i];i++){
			int x=s[i]-'1';
			j++, g[x]++;
			while (j && g[s[i-j+1]-'1']>1) g[s[i-j+1]-'1']--, j--;
			if (g[0] && g[1] && g[2]) ans=min(ans,j);
		}
		cout<<(ans==300000?0:ans)<<endl;
	}
	return 0;
}
