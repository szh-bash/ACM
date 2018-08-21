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
#define N 1000500
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
using namespace std::tr1;
int n, len, ls, f[30], nex[N][30];
char s0[N], s[N];
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
	for (int _=read();_;_--){
		n=read();
		len=0;
		memset(nex,0,sizeof(nex));
		for (int i=1;i<=n;i++){
			scanf("%s", s);
			ls=strlen(s);
			int k=0, j=0;
			for (;j<ls;j++){
				k=nex[k][s[j]-'a'];
				if (!k) break;
			}
			for (int p=j;p<ls;p++)
				s0[len+p-j+1]=s[p];
			memset(f,0,sizeof(f));
			for (int p=len+ls-j;p>len;p--){
				for (int q=0;q<26;q++)
					nex[p][q]=f[q];
				f[s0[p]-'a']=p;
			}
			for (int q=0;q<26;q++)
				if (f[q])
					for (int p=len;p>=0;p--)
						if (nex[p][q]) break;
						else nex[p][q]=f[q];
			len+=ls-j;
		}
		for (int i=1;i<=len;i++) printf("%c", s0[i]);
		cout<<endl;
	}
    return 0;
}
/*
2
2
lubenwei
niubi
3
aa
ab
abb
*/

