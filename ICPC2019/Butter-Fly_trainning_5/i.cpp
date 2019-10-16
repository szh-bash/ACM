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
int trans(int u, int v){
	int a=u%3,b=u/3%3,c=u/9;
	int x=v%3,y=v/3%3,z=v/9;
	if (a==x && b==y && c==z) return 0;
	if (b==x && c==y) return 1;
	if (c==x) return 2;
	return 3;
}
#define C 200
#define M 30
#define N 200000
int q[C], w[C], e[C];
int t[M][M];
int g[C][M];
int f[N][M];
char s[N];
const int inf=999999999;
const int mx=3*3*3;
bool check(char ch, int u){
	int a=u%3,b=u/3%3,c=u/9;
	int x=(a==0)+(b==0)+(c==0);
	int y=(a==1)+(b==1)+(c==1);
	int z=(a==2)+(b==2)+(c==2);
	return q[ch]==x && w[ch]==y && e[ch]==z;
}
int main(){
	scanf("%s", s+1);
	int len=strlen(s+1);
	for (int i=0;i<mx;i++)
		f[0][i]=3;
	q['Y']=3;w['Y']=0;e['Y']=0;
	q['V']=2;w['V']=1;e['V']=0;
	q['G']=2;w['G']=0;e['G']=1;
	
	q['C']=0;w['C']=3;e['C']=0;
	q['X']=1;w['X']=2;e['X']=0;
	q['Z']=0;w['Z']=2;e['Z']=1;
	
	q['T']=0;w['T']=0;e['T']=3;
	q['F']=1;w['F']=0;e['F']=2;
	q['D']=0;w['D']=1;e['D']=2;
	
	q['B']=1;w['B']=1;e['B']=1;
	
	for (char ch='A';ch<='Z';ch++)
		if (q[ch]+w[ch]+e[ch])
			for (int j=0;j<mx;j++) g[ch][j]=check(ch,j);
	for (int i=0;i<mx;i++)
		for (int j=0;j<mx;j++)
			t[i][j]=trans(i,j);
	for (int i=1;i<=len;i++)
		for (int j=0;j<mx;j++){
			f[i][j]=inf;
			if (g[s[i]][j]){
				for (int k=0;k<mx;k++)
					f[i][j]=min(f[i][j],f[i-1][k]+t[k][j]+1);
			}
		}
	int ans=inf;
	for (int i=0;i<mx;i++) ans=min(ans,f[len][i]);
	cout<<ans<<endl;
    return 0;
}
