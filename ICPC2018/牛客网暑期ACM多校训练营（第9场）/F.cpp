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
#define N 6
#define M 200000
#define INF 999999999
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, len0, len[N], tail, st[N][M], son[N][M][26];
char s[N][M], s0[M];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void initial(int u){
	if (len[u]) son[u][0][s[u][1]-'a']=1;
	if (len[u]) son[u][1][s[u][1]-'a']=1;
	if (len[u]>1) son[u][1][s[u][2]-'a']=2;
	for (int i=2, j=0;i<=len[u];i++){
		j=son[u][j][s[u][i]-'a'];
		//if (u==1) cout<<j<<endl;
		for (int k=0;k<26;k++)
			son[u][i][k]=son[u][j][k];
		if (i<len[u]) son[u][i][s[u][i+1]-'a']=i+1;
	}
	//for (int k=0;k<26;k++) son[u][len[u]][k]=len[u];
}
int main(){
	freopen("f.in","r",stdin);
	freopen("f.out","w",stdout);
	n=read();
	int ml=INF;
	for (int i=1;i<=n;i++){
		scanf("%s", s[i]+1);
		len[i]=strlen(s[i]+1);
		initial(i);
		//cout<<"lyk: "<<son[i][0][0]<<' '<<son[i][1][0]<<' '<<son[i][2][0]<<endl;
		ml=min(ml,len[i]);
	}
	scanf("%s", s0);
	len0=strlen(s0);
	cout<<ml<<endl;
	int tail=0;
	for (int i=0;i<len0;i++){
		if (s0[i]=='-'){
			if (tail) tail--;
		}
		else{
			for (int j=1;j<=n;j++) 
				st[j][tail+1]=son[j][st[j][tail]][s0[i]-'a'];
			++tail;
		}
		int ans=INF;
		for (int j=1;j<=n;j++) ans=min(ans,len[j]-st[j][tail]);
		printf("%d\n", ans);
	}
	return 0;
}
