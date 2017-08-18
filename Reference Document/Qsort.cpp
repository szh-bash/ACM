#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, a[11000];
void qsort(int l, int r){
	int i=l, j=r, x=a[l+r>>1];
	while (i<=j){
		while (a[i]<x && i<r) i++;
		while (a[j]>x && j>l) j--;
		if (i<=j) swap(a[i++],a[j--]);
	}
	if (i<r) qsort(i,r);
	if (j>l) qsort(l,j);
}
int main(){
	srand(unsigned(time(NULL)));
	n=300;
	for (int i=1;i<=n;i++) a[i]=rand()%100;
	qsort(1,n);
	for (int i=1;i<=n;i++) cout<<a[i]<<' ';
	return 0;
}
