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
int top;
char op[200000];
ll s[200000], f[200000];
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
	int top=0;
	ll INF = 1LL*(1<<30)*4-1;
	for (int _=read();_;_--){
		scanf("%s", op);
		if (op[0]=='a'){
			s[top]++;
		}
		else if (op[0]=='f'){
			s[++top]=0;
			f[top]=read();
			//scanf("%d", &f[top]);
		}
		else{
			s[top-1]+=f[top]*s[top];
			top--;
		}
		if (s[top]>INF) {
			cout<<"OVERFLOW!!!"<<endl;
			return 0;
		}
	}
	cout<<s[0]<<endl;
	return 0;
}
