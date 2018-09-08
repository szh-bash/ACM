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
#define N 300 
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int lvl[N], topn, topo;
char s[N], sto[N];
struct number{
	ll min, max;
}stn[N], zero;
void wokaishile(){
	char ch=sto[topo--];
		number v=stn[topn--], u=stn[topn--], p;
		if (ch=='+'){
			p.max=u.max+v.max;
			p.min=u.min+v.min;
		}
		else if (ch=='-'){
			p.max=u.max-v.min;
			p.min=u.min-v.max;
		}
		else if (ch=='*'){
			p.max=max(max(u.max*v.max,u.min*v.min), max(u.max*v.min,u.min*v.max));
			p.min=min(min(u.min*v.min,u.max*v.max), min(u.max*v.min,u.min*v.max));
		}
		else{
			p.max=u.max*v.max;
			p.min=u.min;
		}
	stn[++topn]=p;
}
int main(){
	lvl['(']=lvl[')']=0;
	lvl['d']=100;
	lvl['*']=99;
	lvl['+']=lvl['-']=98;
	zero.min=zero.max=0;
	while (~scanf("%s", s)){
		topn=topo=0;
		int len=strlen(s);
		for (int i=0;i<len;){
			if (s[i]>='0' && s[i]<='9'){
				ll p=0;
				while (i<len && s[i]>='0' && s[i]<='9') p=p*10+s[i++]-'0';
				topn++;
				stn[topn].max=stn[topn].min=p;
				continue;
			}
			if (!i && s[i]!='(' || i && s[i-1]=='(' && s[i]!='(') stn[++topn]=zero;
			if (s[i]=='(') sto[++topo]='(';
			else if (s[i]==')'){
				while (topo && sto[topo]!='(') wokaishile();
				topo--;
			}
			else{
				if (s[i]!='d')
					while (topo && lvl[sto[topo]]>=lvl[s[i]])
						wokaishile();
				sto[++topo]=s[i];
			}
			i++;
		}
		while (topo) wokaishile();
		cout<<stn[1].min<<' '<<stn[1].max<<endl;
	}
    return 0;
}
