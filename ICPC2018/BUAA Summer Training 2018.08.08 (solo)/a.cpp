#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
char s[300];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	scanf("%s", s);
	int n=strlen(s), ans=0;
	for (int i=0;i<n;i++){
		for (int j=2;i+j<=n;j+=2){
			int flag=0;
			for (int k=1;k<=j/2;k++)
				if (s[i+k-1]!=s[i+j-k]) flag=1;
			if (flag) continue;
			ans=1;break;
		}
		if (ans) break;
	}
	if (ans) cout<<"Or not."<<endl;
	else cout<<"Odd."<<endl;
    return 0;
}
