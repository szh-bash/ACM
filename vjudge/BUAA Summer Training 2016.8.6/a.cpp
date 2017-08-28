#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int tot, n, ans2[7000], ans3[7000], f[7000], p[7000][30], sum[7000];
char s[3010][3010], ans1[7000];
int main(){
	scanf("%d", &n);
	for (int i=1;i<=n;i++) scanf("%s", &s[i]);
	for (int i=1;i<=n;i++)
		for (int j=0;j<n;j++) 
			if (s[i][j]!='?'){
				if (!p[i][s[i][j]-'a']) sum[i]++;
				p[i][s[i][j]-'a']++;
			}
	for (int i=0;i<n;i++)
		for (int j=1;j<=n;j++)
			if (s[j][i]!='?'){
				if (!p[i+n+1][s[j][i]-'a']) sum[i+n+1]++;
				p[i+n+1][s[j][i]-'a']++;
			}
	for (int i=1;i<=2*n;i++){
		int flag=0;
		for (int k=1;k<=n;k++)
			if (!f[k] && sum[k]<=1){
				for (int j=0;j<n;j++)
					if (s[k][j]!='?'){
						p[j+n+1][s[k][j]-'a']--;
						if (!p[j+n+1][s[k][j]-'a']) sum[j+n+1]--;
						s[k][j]='?';
					}
				int q=2*n-tot;
				ans1[q]='h';
				ans2[q]=k;
				for (int j=0;j<=25;j++)
					if (p[k][j]) ans3[q]=j;
				tot++;
				f[k]=1;
				flag=1;
				break;
			}
		if (flag) continue;
		for (int k=0;k<n;k++)
			if (!f[n+k+1] && sum[n+k+1]<=1){
				for (int j=1;j<=n;j++)
					if (s[j][k]!='?'){
						p[j][s[j][k]-'a']--;
						if (!p[j][s[j][k]-'a']) sum[j]--;
						s[j][k]='?';
					}
				int q=2*n-tot;
				ans1[q]='v';
				ans2[q]=k+1;
				for (int j=0;j<=25;j++)
					if (p[n+k+1][j]) ans3[q]=j;
				tot++;
				f[n+k+1]=1;
				break;
			}
	}
	for (int i=1;i<=2*n;i++){
		cout<<ans1[i]<<' '<<ans2[i]<<' ';
		cout<<char('a'+ans3[i])<<endl;
	}
	return 0;
}
