#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <tr1\unordered_map>
typedef long long ll;
using namespace std;
using namespace std::tr1;
int n;
unordered_map <int, int> mp;
struct njh{
	int op, x, y;
}l[2000000];
int ct, cnt[2000000], c[2000000], d[2000000];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9')  
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		int x, y;
		char op[3];
		scanf("%s%d%d", op, &x, &y);
		if (x>y) swap(x,y);
		l[i].op=op[0]=='+';
		l[i].x=x;
		l[i].y=y;
		cnt[++ct]=x;
		cnt[++ct]=y;
	}
	sort(cnt+1,cnt+1+ct);
	int LSH=0;
	for (int i=1;i<=ct;i++)
		if (cnt[i]!=cnt[i-1]) mp[cnt[i]]=++LSH;
	for (int i=1, tot=0;i<=n;i++)
		if (l[i].op){
			int u=mp[l[i].x], v=mp[l[i].y];
			for (int j=u;j<=LSH;j+=j&(-j)) c[j]=max(c[j],v);
			for (int j=u;j<=LSH;j+=j&(-j)) d[j]++;
			tot++;
		}
		else{
			int u=mp[l[i].x], v=mp[l[i].y], ma=0, sum=0;
			for (int j=u;j;j-=j&(-j)) ma=max(ma,c[j]);
			for (int j=u;j;j-=j&(-j)) sum+=d[j];
			if (ma<=v && sum==tot) printf("YES\n");
			else printf("NO\n");
		}
	return 0;
}
