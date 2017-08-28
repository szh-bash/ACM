#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;
int n, top, l, t[11000], k[11000], tt, ct, f[11000];
char s[11000];
int main(){
	cin>>n;
	scanf("%s", s);
	l=strlen(s);
	t[0]=-999;
	for (int i=0;i<l;i++){
		int v=s[i]-'A';
		if (v<=26) tt++;else ct++;
		if (abs(t[top]-v)=='a'-'A'){
			if (v<=26) f[tt]=k[top];else f[k[top]]=ct;
			top--;
		}
		else{
			t[++top]=v;
			if	 (v<=26) k[top]=tt;else k[top]=ct;
		}
	}
	if (top) cout<<"Impossible"<<endl;
	else{
		for (int i=1;i<tt;i++) cout<<f[i]<<' ';
		cout<<f[tt]<<endl;
	}
	return 0;
}
