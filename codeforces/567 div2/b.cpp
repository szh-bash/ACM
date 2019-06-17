#include <map>
#include <ctime>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 200000
typedef long long ll;
using namespace std;
int n, a[N], b[N], c[N], d[N];
char s[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
ll readll(){
	ll p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	n=read();
	scanf("%s", s+1);
	if (n&1){
		if (s[n/2+1]!='0'){
			n=n/2;
			for (int i=1;i<=n;i++)
				a[i]=s[i]-'0',
				b[i+1]=s[i]-'0';
			a[n+1]=s[n+1]-'0';
			b[1]=s[n+1]-'0';
			int flag=0;
			for (int i=1;i<=n+1;i++)
				if(a[i]<b[i]){
					flag=-1;
					break;
				}
				else if (a[i]>b[i]){
					flag=1;
					break;
				}
			if (flag>0)
				for (int i=1;i<=n+1;i++) a[i]=b[i];
			for (int i=1;i<=(n+1)/2;i++)
				swap(a[i],a[n+1-i+1]);
			for (int i=1;i<=n;i++)
				b[n-i+1]=s[n+1+i]-'0';
			b[n+1]=0;
			n++;
			//for (int i=n;i;i--) printf("%d", a[i]);cout<<endl; 
		}
		else{
			int j=n/2+1;
			for (;j && s[j]=='0';j--);
			int len1, len2;
			if (j>1){
				for (int i=1;i<j;i++)
					a[j-i]=s[i]-'0';
				for (int i=j;i<=n;i++)
					b[n-i+1]=s[i]-'0';
				int ls0=j-1, ls1=n-j+1, jw=0;
				//for (int i=ls0;i;i--) printf("%d", a[i]);cout<<endl;
				//for (int i=ls1;i;i--) printf("%d", b[i]);cout<<endl;
				len1=max(ls0,ls1);
				for (int i=1;i<=len1;i++)
					c[i]=a[i]+b[i]+jw,
					jw=c[i]/10,
					c[i]%=10;
				if (jw) c[++len1]=jw;
				//for (int i=len1;i;i--) printf("%d", c[i]);cout<<endl;
				for (int i=1;i<=len1;i++) a[i]=b[i]=0;
			}
			else len1=0;
			//cout<<len1<<endl;
			for (j=n/2+1;j<=n && s[j]=='0';j++);
			//cout<<j<<' '<<n<<endl;
			if (j<=n){
				for (int i=1;i<j;i++)
					a[j-i]=s[i]-'0';
				for (int i=j;i<=n;i++)
					b[n-i+1]=s[i]-'0';
				int ls0=j-1, ls1=n-j+1, jw=0;
				//for (int i=ls0;i;i--) printf("%d", a[i]);cout<<endl;
				//for (int i=ls1;i;i--) printf("%d", b[i]);cout<<endl;
				len2=max(ls0,ls1);
				for (int i=1;i<=len2;i++)
					d[i]=a[i]+b[i]+jw,
					jw=d[i]/10,
					d[i]%=10;
				if (jw) d[++len2]=jw;
			}
			else len2=0;
			if (!len1){
				len1=len2;
				for (int i=1;i<=len2;i++)
					c[i]=d[i];
			}
			if (!len2){
				len2=len1;
				for (int i=1;i<=len2;i++)
					d[i]=c[i];
			}
			int flag=0;
			int len=max(len1,len2);
			for (int i=len;i;i--) 
				if (c[i]<d[i]) break;
				else if (c[i]>d[i]){
					flag=1;
					break;
				}
			if (flag){
				while (!d[len]) len--;
				for (int i=len;i;i--) printf("%d", d[i]);
			}
			else{
				while (!c[len]) len--;
				for (int i=len;i;i--) printf("%d", c[i]);
			}
			return 0; 
		}
	}
	else{
		if (s[n/2+1]!='0'){
			n=n/2;
			for (int i=1;i<=n;i++)
				a[n-i+1]=s[i]-'0',
				b[n-i+1]=s[n+i]-'0';
		}
		else{
			int j=n/2+1;
			for (;j && s[j]=='0';j--);
			int len1, len2;
			//cout<<j<<endl;
			if (j>1){
				for (int i=1;i<j;i++)
					a[j-i]=s[i]-'0';
				for (int i=j;i<=n;i++)
					b[n-i+1]=s[i]-'0';
				int ls0=j-1, ls1=n-j+1, jw=0;
				len1=max(ls0,ls1);
				for (int i=1;i<=len1;i++)
					c[i]=a[i]+b[i]+jw,
					jw=c[i]/10,
					c[i]%=10;
				if (jw) c[++len1]=jw;
				for (int i=1;i<=len1;i++) a[i]=b[i]=0;
			}
			else len1=0;
			//cout<<len1<<endl;
			for (j=n/2+1;j<=n && s[j]=='0';j++);
			//cout<<j<<endl;
			if (j<=n){
				for (int i=1;i<j;i++)
					a[j-i]=s[i]-'0';
				for (int i=j;i<=n;i++)
					b[n-i+1]=s[i]-'0';
				int ls0=j-1, ls1=n-j+1, jw=0;
				len2=max(ls0,ls1);
				for (int i=1;i<=len2;i++)
					d[i]=a[i]+b[i]+jw,
					jw=d[i]/10,
					d[i]%=10;
				if (jw) d[++len2]=jw;
			}
			else len2=0;
			if (!len1){
				len1=len2;
				for (int i=1;i<=len2;i++)
					c[i]=d[i];
			}
			if (!len2){
				len2=len1;
				for (int i=1;i<=len2;i++)
					d[i]=c[i];
			}
			int flag=0;
			int len=max(len1,len2);
			for (int i=len;i;i--) 
				if (c[i]<d[i]) break;
				else if (c[i]>d[i]){
					flag=1;
					break;
				}
			if (flag){
				while (!d[len]) len--;
				for (int i=len;i;i--) printf("%d", d[i]);
			}
			else{
				while (!c[len]) len--;
				for (int i=len;i;i--) printf("%d", c[i]);
			}
			return 0;
		}
	}
	int jw=0;
	for (int i=1;i<=n;i++)
		a[i]=a[i]+b[i]+jw,
		jw=a[i]/10,
		a[i]%=10;
	if (jw) a[++n]=jw;
	for (int i=n;i;i--) printf("%d", a[i]);cout<<endl; 
	return 0;
}
