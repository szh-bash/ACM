#define N 200005
#include <cstdio>
#include <iostream>
using namespace std;
int cnt, p[N];
char st[N], s[N];
int main(){
	cin>>st; 
	s[cnt++]=' ';
	for (int i=0;st[i];i++) s[cnt++]=st[i], s[cnt++]=' ';
	for (int i=0, rad=-1, cen, j;i<cnt;i++){
		if (rad<i) j=0; else j=min(rad-i+1, p[cen*2-i]);
		for (;i+j<cnt && i>=j && s[i+j]==s[i-j];++j);
		if (i+(p[i]=j)-1>rad)
			rad=i+p[i]-1,
			cen=i;
	}
	int ans=0;
	for (int i=0;i<cnt;i++)
		ans=max(ans,p[i]-1);
	cout<<ans<<endl;
	return 0;
}

