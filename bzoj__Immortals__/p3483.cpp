#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define M 2000010
#define P 131
using namespace std;
string s[2010];
char ch[M], a[M], b[M];
vector <unsigned long long> l[2010], r[2010];
int len[2010], n, m, ans;
void hash(){
	for (int i=1;i<=n;i++){
		unsigned long long x=0, x2=0;
		for (int j=0;j<len[i];j++){
			x=x*P+s[i][j];l[i].push_back(x);
		}
		for (int j=0;j<len[i];j++){
			x2=x2*P+s[i][len[i]-j-1];r[i].push_back(x2);
		}
	}
}
int main(){
	scanf("%d", &n);
	for (int i=1;i<=n;i++){
		scanf("%s", &ch);len[i]=strlen(ch);
		for (int j=0;j<len[i];j++) s[i]+=ch[j];
	}
	hash();
	scanf("%d", &m);ans=0;
	for (int i=1;i<=m;i++){
		unsigned long long aa=0, bb=0;
		int len1, len2;
		scanf("%s", &a);len1=strlen(a);
		for (int j=0;j<len1;j++) a[j]=(a[j]-'a'+ans)%26+'a';
		for (int j=0;j<len1;j++) aa=aa*P+a[j];
		scanf("%s", &b);len2=strlen(b);
		for (int j=0;j<len2;j++) b[j]=(b[j]-'a'+ans)%26+'a';
		for (int j=0;j<len2;j++) bb=bb*P+b[len2-j-1];
		ans=0;
		for (int j=1;j<=n;j++)
			if (l[j][len1-1]==aa && r[j][len2-1]==bb) ans++;
		printf("%d\n", ans);
	}
	return 0;
}
