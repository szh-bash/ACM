#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
int main(){
	char a=getchar(), c=getchar(), b=getchar();
	int n=read()%4;
	int cw[]={118, 60, 94, 62, 118, 60, 94, 62};
	int ccw[]={118, 62, 94, 60, 118, 62, 94, 60};
	int f[200][2];
	f[118][0]=0;f[118][1]=0;
	f[60][0]=1;f[60][1]=3;
	f[94][0]=2;f[94][1]=2;
	f[62][0]=3;f[62][1]=1;
	int f1=0, f2=0;
	if (cw[f[a][0]+n]==b)
		f1=1;
	if(ccw[f[a][1]+n]==b)
		f2=1;
	if (f1 && f2)
		cout<<"undefined"<<endl;
	else
		if (f1) cout<<"cw"<<endl;
		else cout<<"ccw"<<endl;
	return 0;
}
