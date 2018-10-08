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
#define kd 13
#define getn(x) (x-'0')
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int rd, nowc, nown, flag;
char s[10];
int lex[]={10, 2, 3, 4, 5, 6, 7, 8, 9, 'A', 'J', 'K', 'Q'};
int rk[]={'A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K'};
class Player{
public:
	int n, card[100], ct[100];
	void reset(){
		n=0;
		for (int i=1;i<100;i++) ct[i]=0; 
	}
	void init(char ss[], int num){
		reset();
		handle(ss);
		for (int i=1;i<=num;i++){
			scanf("%s", s);
			handle(s);
		}
	}
	void handle(char s[]){
		if (!s[0]) return;
		if (num(s[1])) ct[card[++n]=10]++;
		else
			if (num(s[0])) ct[card[++n]=getn(s[0])]++;
			else ct[card[++n]=s[0]]++;
	}
	void print(){
		if (!n) {printf("WINNER\n");return;}
		for (int i=0;i<13;i++)
		for (int j=1;j<=ct[rk[i]];j++)
			(rk[i]<10?printf("%c ",'0'+rk[i])
			:rk[i]==10?printf("%s ","10")
			:printf("%c ",rk[i]));
		puts("");
	}
	int has(int v){
		return this->ct[v];
	}
	int getmin(){
		for (int i=0;i<13;i++)
			if (ct[lex[i]]) return lex[i];
		return 0;
	}
	int getminct(){
		int mi=1000, tmp;
		for (int i=0;i<13;i++)
			if (ct[lex[i]] && ct[lex[i]]<mi)
				mi=ct[lex[i]],
				tmp=lex[i];
		return tmp;
	}
	void throws(int v, int m, Player &e){
		ct[v]-=m;
		for (int i=1;i<=n && m;i++)
			if (card[i]==v){
				e.add(v);
				card[i--]=card[n--];
				m--;
			}
	}
	void add(int v){
		ct[card[++n]=v]++;
	}
	void eatup(Player &e){
		for (int i=1;i<=e.n;i++) add(e.card[i]);
		e.reset();
	}
	bool empty(){
		return ! this->n; 
	}
};
Player a;
Player b;
Player c;
Player d;
Player e;
void initial(){
	rd=0;
	a.init(s,12);
	b.init("",13);
	c.init("",13);
	d.init("",13);
	e.reset();
}
bool AC(){
	if (e.empty()) return 0;
	int v=rk[rd%13];
	bool ff=(rd%4==0 && !a.has(v));
	if (ff || (nown+a.has(nowc)>4))
		if (flag){
			a.eatup(e);
			return 0;
		}
		else return 1;
	return 0;
}
bool BC(){
	if (e.empty()) return 0;
	int v=rk[rd%13];
	bool ff=(rd%4==1 && !b.has(v));
	if (ff)
		if (flag){
			b.eatup(e);
			return 0;
		}
		else return 1;
	return 0;
}
bool CC(){
	if (e.empty()) return 0;
	if (c.has(nowc)==4) return 1;
	return 0;
}
bool DC(Player now){
	if (e.empty()) return 0;
	if (now.empty())
		if (flag){
			d.eatup(e);
			return 0;
		}
		else return 1;
	return 0;
}
void A();
void D(){
	int v=rk[(rd++)%13];
	nowc=v;
	nown=d.has(v);
	flag=nown>2;
	d.throws(v,nown,e);
	if (!flag){
		v=d.getmin();
		if (v)
			nown++,
			d.throws(v,1,e);
		else flag=1;
	}
	if (AC() || BC() || CC()) d.eatup(e);
	if (!d.empty()) A();
}
void C(){
	int v=rk[(rd++)%13];
	nown=flag=c.has(v);
	nowc=v;
	if (!flag){
		v=c.getminct();
		nown=c.has(v);
	}
	c.throws(v,nown,e);
	if (AC() || BC() || DC(c)) c.eatup(e);
	if (!c.empty()) D();
}
void B(){
	int v=rk[(rd++)%13];
	nown=flag=b.has(v);
	nowc=v;
	if (!flag){
		nown=1;
		v=b.getmin();
	}
	b.throws(v,nown,e);
	if (AC() || CC() || DC(b)) b.eatup(e);
	if (!b.empty()) C();
}
void A(){
	int v=rk[(rd++)%13];
	nown=1;
	nowc=v;
	flag=a.has(v);
	if (!flag) v=a.getmin();
	a.throws(v,1,e);
	if (BC() || CC() ||DC(a)) a.eatup(e);
	if (!a.empty()) B();
}
void print(){
	a.print();
	b.print();
	c.print();
	d.print();
}
int main(){
	while (~scanf("%s", s)){
		initial();
		A();
		print();
	}
    return 0;
}
