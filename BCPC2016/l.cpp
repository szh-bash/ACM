#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
char s[110][110];
int n, m;
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T;
	cin>>T;
	while (T--){
		cin>>n>>m;
		int a=0, b=0, c=0;
		for (int i=1;i<=n;i++)
			scanf("%s", s[i]);
		for (int i=1;i<=n;i++)
			for (int j=0;j<m;j++)
				if (s[i][j]=='.'){
					for (int k=1;k<=j && k+j<m && i+2*k<=n
							  && s[i+2*k-1][j]=='.'
							  && s[i+2*k][j]=='.'
							  && s[i][j-k]=='.'
							  && s[i][j+k]=='.';k++) a++;
							  
							  
					for (int k=1;k<i && k+j<m && s[i-k][j]=='.' && s[i][j+k]=='.';k++) b++;
					
					
					for (int k=1;2*k<i && i+2*k<=n && k<=j && k+j<m;k++){
						int flag=1;
						for (int p=j-k;p<=j+k;p++)
							if (s[i][p]!='.' || s[i-2*k][p]!='.' || s[i+2*k][p]!='.') {flag=0;break;}
						for (int p=i-2*k;p<=i;p++)
							if (s[p][j-k]!='.') {flag=0;break;}
						for (int p=i+2*k;p>=i;p--)
							if (s[p][j+k]!='.') {flag=0;break;}
						c+=flag;
					}
					if (j+1<m && s[i][j+1]=='.')
					for (int k=1;2*k+1<i && i+2*k+1<=n && k<=j && k+j+1<m;k++){
						int flag=1;
							for (int p=j-k;p<=j+k+1;p++)
							if (s[i][p]!='.' || s[i-2*k-1][p]!='.' || s[i+2*k+1][p]!='.') {flag=0;break;}
						for (int p=i-2*k-1;p<=i;p++)
							if (s[p][j-k]!='.') {flag=0;break;}
						for (int p=i+2*k+1;p>=i;p--)
							if (s[p][j+k+1]!='.') {flag=0;break;}
						c+=flag;
					}
					
					
				}
		cout<<a<<' '<<b<<' '<<c<<endl;
	}
	return 0;
}
