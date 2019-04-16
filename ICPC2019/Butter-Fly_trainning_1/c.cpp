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
int m, n, k, s_min, s_max;
char let[35], ch[100][35][35], s[35];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
int main(){
	cout<<(int)' '<<endl;
	while (~scanf("%d%d%d%d%d", &m, &n, &k, &s_min, &s_max)){
		for (int i=1;i<=m;i++)
			for (int j=1;j<=k;j++) ch[' '][i][j]='.';
		scanf("%s", s);
		int t=0;
		while (s[0]>='A' && s[0]<='Z'){
			let[++t]=s[0];
			scanf("%s", s);
			strcpy(ch[let[t]][1],s);
			scanf("%s", s);
		}
		for (int i=2;i<=m;i++)
			for (int j=1;j<=t;j++){
				strcpy(ch[let[j]][i],s);
				if (i<m || j!=t) scanf("%s", s);
			}
		/*for (int i=1;i<=t;i++){
			cout<<let[i]<<endl;
			for (int j=1;j<=m;j++)
				cout<<ch[let[i]][j]<<endl;
		}*/
		
		char letter=getchar();
		while (letter!=' ' && (letter<'A' || letter>'Z')) letter=getchar();
		int cur=0, col=0, ct=0;
		while (letter==' ' || letter>='A' && letter<='Z') s_before[cur++]=letter, letter=getchar();
		while (cur--){
			int x=read();
			ct++;
			for (int i=1;i<=m;i++)
				for (int j=col+1;j<=col+x;j++)
					a[i][j]=0;
			col+=x;
			for (int i=1;i<=m;i++)
				for (int j=col+1;j<=col+k;j++)
					a[i][j]=ch[s_before[ct]][i][j-col]=='*';
			col+=k;
		}
		for (int i=1;i<=m;i++)
			for (int j=col+1;j<=n;j++) a[i][j]=0;
		
		for (int i=1;i<=m;i++)
			for (int j=1;j<=n;j++){
				bs[i][j].reset();
				for (int t=1;t<=k && t+j-1<=n;t++)
					bs[i][j][t]=a[i][j+k-1];
			}
			
		letter=getchar();
		while (letter!=' ' && (letter<'A' || letter>'Z')) letter=getchar();
		cur=0, col=0, ct=0;
		while (letter==' ' || letter>='A' && letter<='Z') l[cur++]=letter, letter=getchar();
		
		for (int i=1;i<=n;i++)
			for (int j=0;j<cur;j++)
				for (int p=s_min;p<=s_max;p++){
					
				}
	}
    return 0;
}
/*
5 53 5 1 2
A ..*.. C .**** E ***** I ..*.. M *...* N *...* P ****. R ****.
.*.*. *.... *.... ..*.. **.** **..* *...* *...*
*...* *.... ***.. ..*.. *.*.* *.*.* ****. ****.
***** *.... *.... ..*.. *...* *..** *.... *.*..
*...* .**** ***** ..*.. *...* *...* *.... *..*.
ACM ICPC
3 1 1 1 1 1 1 1
NEERC
*/
