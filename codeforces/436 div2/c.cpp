#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') (ch=='-'?q=-1:0), ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	int a=read(), b=read(), f=read(), k=read(), ans=0;
	if (f>b || a-f>b || k>=2 && 2*(a-f)>b || k>=3 && 2*f>b){
		cout<<-1<<endl;
		return 0;
	}
	int t=b;
	for (int i=1;i<=k;i++)
		if (i&1){
			if (t<f){
				t=b-2*f;
				ans++;
			}else t-=f;
			if (t<a-f){
				t=b-a+f;
				ans++;
			}else t-=a-f;
		}
		else{
			if (t<a-f){
				t=b-2*(a-f);
				ans++;
			}else t-=a-f;
			if (t<f){
				t=b-f;
				ans++;
			}else t-=f;
		}
	cout<<ans<<endl;
	return 0;
}
