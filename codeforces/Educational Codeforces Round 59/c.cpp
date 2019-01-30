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
typedef long long ll;
using namespace std;
priority_queue <int> q;
//priority_queue<int, vector<int>, less<int> > q;
int a[300000];
char s[300000];
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
		int n=read(), k=read();
		for (int i=1;i<=n;i++) a[i]=read();
		scanf("%s",s+1);
		int tp=0;
		ll ans=0;
		for (int i=1;i<=n;i++){
			if (tp!=s[i]){
				int tk=k;
				while (tk-- && !q.empty()){
					ans+=q.top();
					q.pop();
				}
				while (!q.empty()) q.pop();
				tp=s[i];
			}
			q.push(a[i]);
		}
		int tk=k;
		while (tk-- && !q.empty()){
			ans+=q.top();
			q.pop();
		}
		while (!q.empty()) q.pop();
		printf("%I64d\n", ans);
	return 0;
}
