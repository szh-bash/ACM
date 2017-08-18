#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n;
char s[100][100];
int main(){
	cin>>n;
	for (int i=1;i<=n;i++) scanf("%s", s[i]);
	int ls=strlen(s[1]);
	int ans1=1000000;
	for (int i=1;i<=n;i++){
		int ans=0;
		for (int j=1;j<=n;j++)
			if (i!=j){
				int k;
				for (k=0;k<ls;k++){
					int flag=1, m, p;
					for (m=0,p=k;p<ls;p++,m++)
						if (s[i][m]!=s[j][p]) flag=0;
					for (p=0;m<ls;m++,p++)
						if (s[i][m]!=s[j][p]) flag=0;
					if (!flag) continue;
					ans+=k;
					break;
				}
				if (k==ls){
					cout<<-1<<endl;
					return 0;
				}
			}
		ans1=min(ans,ans1);
	}
	cout<<ans1<<endl;
	return 0;
}
