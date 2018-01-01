#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
map <string,int> mp;
int n, g[100], m;
char s[100], name[100][100], ans[30][100][100];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9')
		(ch=='-'?q=-1:0),
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
bool check(char *x, char *y){
	int l1=strlen(x), l2=strlen(y), flag=1;
	for (int j=0;j<l1 && j<l2;j++)
		if (x[l1-j-1]!=y[l2-j-1]) flag=0;
	if (flag && l1>=l2) return 1;
	return 0;
}
int main(){
	n=read();
	//cout<<n<<endl;
	for (int i=1;i<=n;i++){
		scanf("%s", name[i]);
		strcpy(s,name[i]);
		//cout<<i<<endl;
		//cout<<s<<' '<<name[i]<<endl;
		if (!mp[s]) mp[s]=i;
		else i--,n--;
		int u=mp[s], k;
		scanf("%d", &k);
		for (;k;k--){
			scanf("%s", s);
			//cout<<strlen(s)<<endl;
			//cout<<s<<endl;
			int flag=0;
			for (int j=1;j<=g[u];j++)
				if (check(ans[u][j],s)){
					flag=1;
					break;
				}
				else
					if (check(s,ans[u][j])){
						if (flag)
							strcpy(ans[u][j],ans[u][g[u]--]),
							j--;
						else
							strcpy(ans[u][j],s),
							flag=1;
					}
			if (!flag) strcpy(ans[u][++g[u]],s);
		}
	}
	cout<<n<<endl;
	//cout<<"lyk"<<endl;
	for (int i=1;i<=n;i++){
		cout<<name[i]<<' '<<g[i];
		for (int j=1;j<=g[i];j++)
			cout<<' '<<ans[i][j];
		cout<<endl;
	}
	return 0;
}
