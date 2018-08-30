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
char s[100000];
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
	for (int _=read();_;_--){
		int p=read();
		int ct=0;
		for (int j=0;j<p;j++) s[ct++]='1', s[ct++]=' ';s[ct]='\0';
		for (int i=0;i<p;i++)
			puts(s);
		for (int i=0;i<p;i++){
			ct=0;
			for (int j=0;j<p-1;j++) s[ct++]='1', s[ct++]=' ';
			if (!i) s[ct++]='1';
			else
				if (i==1) s[ct++]=p-1+'0';
				else s[ct++]=i-1+'0';
			s[ct]='\0';
			puts(s);
		}
	}
    return 0;
}










