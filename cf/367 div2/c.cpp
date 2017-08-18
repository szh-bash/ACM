#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n, l1, l2, c[101000];
long long f[101000][4], cnt;
char ch1[101000], ch2[101000], s1[101000], s2[101000];
void work(int t, int a, int b){
	int p=0;
	if (a)
		for (int i=0;i<l1;i++) ch1[i]=s1[l1-i-1];
		else 
			for (int i=0;i<l1;i++) ch1[i]=s1[i];
	if (b)
		for (int i=0;i<l2;i++) ch2[i]=s2[l2-i-1];
		else
			for (int i=0;i<l2;i++) ch2[i]=s2[i];
	for (int i=0;i<min(l1,l2);i++){
		if (ch1[i]>ch2[i]) return;
		if (ch1[i]<ch2[i]) {p=1;break;}
	}
	if (!p && l1>l2) return;
	f[t][b]=min(f[t][b],f[t-1][a]+(long long)b*c[t]);
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++) scanf("%d", &c[i]);
	scanf("%s", s1);
	l1=strlen(s1);
	f[1][1]=c[1];
	cnt=(long long) 999999999*99999999;
	for (int i=2;i<=n;i++) f[i][0]=f[i][1]=cnt;
	for (int i=2;i<=n;i++){
		scanf("%s", s2);
		l2=strlen(s2);
		work(i,0,0);
		work(i,0,1);
		work(i,1,0);
		work(i,1,1);
		if (f[i][0]==cnt && f[i][1]==cnt){
			cout<<-1<<endl;
			return 0;
		}
		for (int i=0;i<l2;i++) s1[i]=s2[i];
		l1=l2;
	}
	if (f[n][0]<f[n][1]) cout<<f[n][0]<<endl;
	else cout<<f[n][1]<<endl;
	return 0;
}
