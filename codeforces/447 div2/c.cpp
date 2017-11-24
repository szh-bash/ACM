#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int s[5000];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
int main(){
	int m=read();
	for (int i=1;i<=m;i++) s[i]=read();
	if (s[1]>1)
		for (int i=1;i<=m;i++)
			if (s[i]%s[1]) {
				cout<<-1<<endl;
				return 0;
			}
	if (m==1) cout<<1<<endl;else cout<<(m-1)*2<<endl;
	for (int i=m;i>1;i--) printf("%d %d ", s[i], s[1]);
	if (m==1) cout<<s[1]<<endl;
	return 0;
}
