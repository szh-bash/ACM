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
int k, a[100][100];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void print(int n){
	int m=0;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (a[i][j]) m++;
	cout<<n<<' '<<m<<endl;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (a[i][j]) printf("%d %d\n", i, j);
}
int main(){
	//freopen("E_test.out","w",stdout);
//for (int _=999000;_<=1000000;_++){
	int tmp=k=read();
	//k=_;
	int i=72;
	for (;i*(i-1)*(i-2)*(i-3)/24>k;i--);
	for (;i;i--){
		memset(a,0,sizeof(a));
		k=tmp-i*(i-1)*(i-2)*(i-3)/24;
		for (int j1=1;j1<=i;j1++)
			for (int j2=j1+1;j2<=i;j2++)
				a[j1][j2]=1;
		if (!k) { print(i); return 0;}
		
		int t=0;
		while (k && i+t<=75){
			t++;
			int j=i;
			for (;j*(j-1)*(j-2)/6>k;j--);
			k-=j*(j-1)*(j-2)/6;
			for (int j1=1;j1<=j;j1++)
				a[j1][i+t]=1;
		}
		if (i+t>75) continue;
		else{
			print(i+t);
			return 0;
		}
	}
	i=72;
	for (;i*(i-1)*(i-2)*(i-3)/24>tmp;i--);
	for (;i;i--){
		memset(a,0,sizeof(a));
		k=tmp-i*(i-1)*(i-2)*(i-3)/24;
		for (int j1=1;j1<=i;j1++)
			for (int j2=j1+1;j2<=i;j2++)
				a[j1][j2]=1;
		if (!k) { print(i); return 0;}
		
		int t=0;
		
		while (k && i+t<=72){
			t++;
			int j=i;
			for (;j*(j-1)*(j-2)/6>k;j--);
			k-=j*(j-1)*(j-2)/6;
			for (int j1=1;j1<=j;j1++)
				a[j1][i+t]=1;
		}
		if (!k) { print(i+t);return 0;}
		
		int j=i;
		for (;j*(j-1)/2+j*(j-1)*(j-2)/3>k;j--);
		k-=j*(j-1)/2+j*(j-1)*(j-2)/3;
		a[i+t+1][i+t+2]=1;
		for (int j1=1;j1<=j;j1++)
			for (int j2=j1+1;j2<=j;j2++)
				a[j1][i+t+1]=a[j1][i+t+2]=a[j2][i+t+1]=a[j2][i+t+2]=1;
		
		if (i+t+2>75 || k) continue;
		else{
			print(i+t+2);
			return 0;
		}
	}
	
	i=72;
	for (;i*(i-1)*(i-2)*(i-3)/24>tmp;i--);
	for (;i;i--){
		memset(a,0,sizeof(a));
		k=tmp-i*(i-1)*(i-2)*(i-3)/24;
		for (int j1=1;j1<=i;j1++)
			for (int j2=j1+1;j2<=i;j2++)
				a[j1][j2]=1;
		if (!k) { print(i); return 0;}
		
		int t=2;
		int j=i;
		for (;j*(j-1)/2+j*(j-1)*(j-2)/3>k;j--);
		k-=j*(j-1)/2+j*(j-1)*(j-2)/3;
		a[i+1][i+2]=1;
		for (int j1=1;j1<=j;j1++)
			for (int j2=j1+1;j2<=j;j2++)
				a[j1][i+1]=a[j1][i+2]=a[j2][i+1]=a[j2][i+2]=1;
		if (!k) { print(i+t); return 0;}
		
		while (k && i+t<=72){
			t++;
			int j=i;
			for (;j*(j-1)*(j-2)/6>k;j--);
			k-=j*(j-1)*(j-2)/6;
			for (int j1=1;j1<=j;j1++)
				a[j1][i+t]=1;
		}
		if (!k) { print(i+t);return 0;}
		
		j=i;
		for (;j*(j-1)/2+j*(j-1)*(j-2)/3>k;j--);
		k-=j*(j-1)/2+j*(j-1)*(j-2)/3;
		a[i+t+1][i+t+2]=1;
		for (int j1=1;j1<=j;j1++)
			for (int j2=j1+1;j2<=j;j2++)
				a[j1][i+t+1]=a[j1][i+t+2]=a[j2][i+t+1]=a[j2][i+t+2]=1;
		
		if (i+t+2>75 || k) continue;
		else{
			print(i+t+2);
			return 0;
		}
	}
    return 0;
}
