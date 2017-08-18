#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int n, f[200];
char s1[110000], s0[110000], s[110000];
int main(){
	scanf("%s%s", s0, s1);
	int p=-1, l1=strlen(s1), l0=strlen(s0);
	for (int i=0;i<l0;i++)
		f[s0[i]]=1;
	for (int i=0;i<l1;i++)
		if (s1[i]=='*') p=i;
	cin>>n;
	while(n--){
		scanf("%s", s);
		int l=strlen(s);
		if (p<0){
			if (l!=l1){
				cout<<"NO"<<endl;
				continue;
			}
			int flag=0;
			for (int i=0;i<l;i++){
				if (s1[i]==s[i]) continue;
				if (s1[i]!='?' || !f[s[i]]){
					flag=1;
					break;
				}
			}
			if (flag) cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}
		else{
			if (l1-1>l){
				cout<<"NO"<<endl;
				continue;
			}
			int flag=0;
			for (int i=0;i<p;i++){
				if (s1[i]==s[i]) continue;
				if (s1[i]!='?' || !f[s[i]]){
					flag=1;
					break;
				}
			}
			int t=l1-p-1;
			for (int i=p+1;i<l1;i++){
				if (s1[i]==s[l-t+(i-p-1)]) continue;
				if (s1[i]!='?' || !f[s[l-t+(i-p-1)]]){
					flag=1;
					break;
				}
			}
			for (int i=p;i<l-t;i++)
				if (f[s[i]]){
					flag=1;
					break;
				}
			if (flag) cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}
	}
	return 0;
}
