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
	k=read();
	int i=71;
	for (;i*(i-1)*(i-2)*(i-3)/24>k;i--);
	k-=i*(i-1)*(i-2)*(i-3)/24;
	cout<<k<<endl;
	for (int j1=1;j1<=i;j1++)
		for (int j2=j1+1;j2<=i;j2++)
			a[j1][j2]=1;
	if (!k) { print(i); return 0;}
	
	int j=i, t1=0;
	for (;j*(j-1)/2+j*(j-1)*(j-2)/3>k;j--);
	k-=j*(j-1)/2+j*(j-1)*(j-2)/3;
	cout<<k<<endl;
	a[i+1][i+2]=1;
	for (int j1=1;j1<=j;j1++)
		for (int j2=j1+1;j2<=j;j2++)
			a[j1+t1][i+1]=a[j1+t1][i+2]=a[j2+t1][i+1]=a[j2+t1][i+2]=1;
	if (!k) { print(i+2); return 0;}
	
	j=i;
	for (;j*(j-1)*(j-2)/6>k;j--);
	k-=j*(j-1)*(j-2)/6;
	cout<<k<<endl;
	for (int j1=1;j1<=j;j1++)
		a[j1][i+3]=1;
	if (!k) { print(i+3); return 0;}
	
	j=i;
	for (;j*(j-1)*(j-2)/6>k;j--);
	k-=j*(j-1)*(j-2)/6;
	cout<<k<<endl;
	for (int j1=1;j1<=j;j1++)
		a[j1][i+4]=1;
	if (!k) { print(i+4); return 0;}
	/*
	int t2=j+t1;
	a[i+3][i+4]=1;
	for (j=i-t2;j*(j-1)/2+j*(j-1)*(j-2)/3>k;j--);
	for (int j1=1;j1<=j;j1++)
		for (int j2=j1+1;j2<=j;j2++)
			a[j1+t2][i+3]=a[j1+t2][i+4]=a[j2+t2][i+3]=a[j2+t2][i+4]=1;
	k-=j*(j-1)/2+j*(j-1)*(j-2)/3;
	cout<<k<<endl;
	if (!k) { print(i+4); return 0;}
	
	int t3=j+t2;
	for (j=i-t3;j*(j-1)/2+j*(j-1)*(j-2)/3>k;j--);
	for (int j1=1;j1<=j;j1++)
		for (int j2=j1+1;j2<=j;j2++)
			a[j1+t3][i+2]=a[j1+t3][i+4]=a[j2+t3][i+2]=a[j2+t3][i+4]=1;
	k-=j*(j-1)/2+j*(j-1)*(j-2)/3;
	//if (k==1) a[i+1][i+2]=a[i+1][i+3]=a[i+1][i+4]=a[i+2][i+3]=a[i+2][i+4]=a[i+3][i+4]=1;
	print(i+4);
	cout<<k<<endl;*/
    return 0;
}
