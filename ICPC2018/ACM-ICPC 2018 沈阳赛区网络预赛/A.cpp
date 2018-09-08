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
#include <tr1/unordered_map>
#define N 200000
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, x, a, b, p[N];
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
		n=read();x=read();
		a=read();b=read();
		int sum=0, cnt=0, flag=0;
		for (int i=1;i<=a;i++){
			p[i]=read();
			if (flag) continue;
			if (p[i]==p[i-1]+1) {cnt++; continue;}
			cout<<i<<' '<<cnt<<endl; 
			if ((ll)cnt*x+sum>=n){
				flag=1;
				printf("Gudako\n");
				continue;
			//	break;
			}
			else sum+=cnt;
			cnt=1;
			if ((ll)(p[i]-p[i-1]-1)*x+sum>=n){
				flag=1;
				printf("Ritsuka\n");
				continue;
			//	break;
			}
			else sum+=p[i]-p[i-1]-1;
		}
		if (flag) continue;
		if ((ll)cnt*x+sum>=n){
			printf("Gudako\n");
			continue;
		}
		printf("Ritsuka\n");
	}
    return 0;
}
