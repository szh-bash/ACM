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
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, x, base;
char s[20000];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int reads(){
	int p=0, q=1;
	while (s[x] && !num(s[x])) x++;
	while (s[x] && num(s[x])) p=p*10+s[x++]-'0', q=0;
	return p+q;
}
int power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
int solve(){
	n=read();
	int res=0;
	for (int i=1;i<=n;i++){
		scanf("%s", s);
		if (s[0]=='b'){
			scanf("%s", s);
			base=1;
		}
		else if (s[0]=='c'){
			scanf("%s", s);
			base=1;
		}
		else if (s[0]=='i'){
			scanf("%s", s);
			base=4;
		}
		else if (s[0]=='l'){
			//long long, long double
			scanf("%s", s);
			if (!strcmp(s,"long")) base=8;
			else base=16;
			scanf("%s", s);
		}
		else if (s[0]=='_'){
			scanf("%s", s);
			base=16;
		}
		else if (s[0]=='f'){
			scanf("%s", s);
			base=4;
		}
		else if (s[0]=='d'){
			scanf("%s", s);
			base=8;
		}
		x=0;
		res+=base*reads();
//		cout<<i<<' '<<s<<' '<<base<<' '<<res<<endl;
	}
	res=res/1024+(res%1024>0);
	return res;
}
int main(){
	for (int _=read(), o=1;_;_--,o++) 
		printf("Case #%d: %d\n", o, solve());
    return 0;
}
