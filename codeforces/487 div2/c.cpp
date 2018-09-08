#include <map>
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
int n, m, k;
char a[60][60];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
struct qlz{
	int n;
	char c;
}l[7];
bool cmp(qlz a, qlz b){ return a.n<b.n;}
int check(int i,int j){
	if (a[i][j]) return 0;
	if (a[i-1][j]==l[0].c) return 1;
	if (a[i][j+1]==l[0].c) return 1;
	if (a[i+1][j]==l[0].c) return 1;
	if (a[i][j-1]==l[0].c) return 1;
	return 0;
}
int main(){
	k=4;
	n=50;m=50;
	for (int i=0;i<k;i++) l[i].n=read(), l[i].c='A'+i;
	sort(l,l+k,cmp);
	for (int i=1;i<=n && l[0].n>1;i++)
		for (int j=1;j<=m && l[0].n>1;j++)
			if ((i&1)==(j&1)){
				a[i][j]=l[0].c;
				l[0].n--;
			}
	int tot=0;
	for (int i=1;i<=n && tot<3;i++)
		for (int j=1;j<=m && tot<3;j++)
			if (check(i,j))
				for (int p=1;p<k;p++)
					if (l[p].n){
						a[i][j]=l[p].c;
						if (--l[p].n==0) tot++;
						break;
					}
	for (int i=n;i && tot<3;i--)
		for (int j=1;j<=m && tot<3;j++)
			if ((i&1) && (j&1))
				for (int p=1;p<k;p++)
					if (l[p].n){
						a[i][j]=l[p].c;
						if (--l[p].n==0) tot++;
						break;
					}
	cout<<n<<' '<<m<<endl;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (!a[i][j]) a[i][j]=l[0].c;
	for (int i=1;i<=n;i++) printf("%s\n", a[i]+1);
	return 0;
}
