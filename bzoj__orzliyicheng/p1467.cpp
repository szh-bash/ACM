#include <map>
#include <cmath> 
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define LL long long
using namespace std;
int x, y, z;
map<int,int>mp;
int gcd(int a, int b){return b?gcd(b,a%b):a;}
int power(LL a, int b){
	LL c=1;
	while (b){
		if (b&1) c=c*a%z;
		a=a*a%z;
		b/=2;
	}
	return c;
}
void exgcd(int a, int b, int &c, int &d){
	if (!b){
		c=1;d=0;
		return;
	}
	exgcd(b,a%b,c,d);
	int t=c;
	c=d;
	d=t-a/b*d;
}
int main(){
	while (scanf("%d%d%d",&x, &z, &y)!=EOF){
		if (z==0) break;
		if (x==1 && y==1 && z==1) {cout<<0<<endl;continue;}
		y%=z;
		if (y==1) {cout<<0<<endl;continue;}
		if (x%z==0 && y){cout<<"No Solution"<<endl;continue;}
		if (x%z && !y){cout<<"No Solution"<<endl;continue;}
		int D=gcd(x,z),zz=z,G=1,r=0,flag=0,tmp=1,a,m,phi;
		while (D!=1){
			r++;
			zz/=D;
			G=G*D;
			D=gcd(x,zz);
		}
		if (y%G){cout<<"No Solution"<<endl;continue;}
		for (int i=1;i<=r;i++){
			D=(LL)D*x%z;
			if (D==y){
				cout<<i<<endl;
				flag=1;
				break;
			}
		}
		//cout<<r<<endl;
		if (flag) continue;
		mp.clear();
		z=phi=zz;
		y=(LL)y*power(G,z-2)%z;
		a=(LL)D*power(G,z-2)%z;
		m=floor(sqrt(z-r))+1;
		D=power(x,m);
		for (int i=1;i<=m;i++)
			tmp=(LL)tmp*x%z, mp[tmp]=mp[tmp]?mp[tmp]:i;
		tmp=a;
		for (int i=2;i<=1+floor(sqrt(z));i++)
			if (zz%i==0){
				while (zz%i==0) zz/=i;
				phi=phi/i*(i-1);
			}
		if (zz>1) phi=phi/zz*(zz-1);
		for (int i=0;i<=m;i++){
			int c, d;
			exgcd((LL)tmp*power(y,phi-1)%z,z,c,d);
			c=(c+z)%z;
			if (mp[c] || c==1){
				cout<<i*m+mp[c]+r<<endl;
				flag=1;
				break;
			}
			tmp=(LL)tmp*D%z;
		}
		if (!flag) cout<<"No Solution"<<endl;
	}
	return 0;
}
