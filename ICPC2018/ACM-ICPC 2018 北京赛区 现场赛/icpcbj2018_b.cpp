#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define M 200*2000
#define num(x) ((x)>='0' && (x)<='9')
#define let(x) ((x)>='a' && (x)<='z')
#define nice(x) (num(x) || let(x) || x==' ')
typedef long long ll;
using namespace std;
int cnt, ct, x, loc, flag_h, flag_t, flag_ex, flag_num;
int pi[M], w;
ll ans[M];
int ans_li[M];
char s[M];
char s0[2000];
ll get_num(){
	ll p=0;
	w=0;
//	cout<<x<<endl;
	while (x<cnt && !num(s[x])){
//		cout<<"fk "<<s[x]<<' '<<x<<endl;
		flag_h=let(s[x]);
		x++;
	}
//	cout<<"over "<<x<<endl;
	if (flag_h && num(s[x]) && pi[x-1]!=pi[x]) flag_h=0;
	if (num(s[x])) loc=pi[x], flag_num=1;else flag_num=0;
//	cout<<x<<endl;
	while (x<cnt && num(s[x])){
//		cout<<"lykk "<<s[x]<<endl;
		w+=(!p) && s[x]=='0', p=p*10+s[x++]-'0';
	}
//	cout<<p<<' '<<x<<" lyk"<<endl;
	if (!p) w--;
	return p;
}
int main(){
	memset(s,0,sizeof(s));
	while (gets(s0)!=NULL){
		int len=strlen(s0);
		ct++;
		for (int i=0;i<len;i++)
			if (nice(s0[i])) pi[cnt]=ct, s[cnt++]=s0[i];
	}
	s[cnt]=' ';
//	cout<<cnt<<endl;
//	cout<<s<<endl;
	while (x<cnt){
		ll v=get_num();
		if (flag_num && !w && (!let(s[x]) || pi[x]!=pi[x-1]) && !flag_h ) ans[++ans[0]]=v, ans_li[loc]++;
	}
	for (int i=1;i<=ans[0];i++) printf("%lld ", ans[i]);puts("");
	for (int i=1;i<=ct;i++) printf("%d\n", ans_li[i]);
	return 0;
}
