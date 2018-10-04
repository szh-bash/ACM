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
#define getn(x) (x-'0')
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
char s[10];
int lex[]={10, 2, 3, 4, 5, 6, 7, 8, 9, 'A', 'J', 'K', 'Q'};
class Player{
public:
	int n, card[100], ct[100];
	void init(char ss[], int num){
		reset();
		handle(ss);
		for (int i=1;i<=num;i++){
			scanf("%s", s);
			handle(s);
		}
		print();
	}
	void handle(char s[]){
		if (!s[0]) return;
		if (num(s[1])) ct[card[++n]=10]++;
		else
			if (num(s[0])) ct[card[++n]=getn(s[0])]++;
			else ct[card[++n]=s[0]]++;
	}
	void reset(){
		n=0;
		for (int i=1;i<100;i++) ct[i]=0; 
	}
	void print(){
		for (int i=1;i<=n;i++) 
			(card[i]<10?printf("%c ",'0'+card[i])
			:card[i]==10?printf("%s ","10")
			:printf("%c ",card[i]));
		puts("");
	}
	bool has(int v){
		return a.ct[v];
	}
	int getnextlex(int x){
	}
	int getmin(){
		for (int i=0;i<13;i++)
			if (ct[lex[i]]) return lex[i];
	}
	void throws(int v, int m){
		e.get(v,m);
		ct[v]-=m;
		for (int i=1;i<=n && m;)
			if (card[i]==v){
				card[i]=card[n--];
				m--;
			}
	}
	void eatup(){
		for (int i=1;i<=e.n;i++)
			card[++n]=e.card[i],
			ct[e.card[i]]++;
		e.reset();
	}
};
Player a;
Player b;
Player c;
Player d;
Player e;
void initial(){
	a.init(s,12);
	b.init("",13);
	c.init("",13);
	d.init("",13);
	e.reset();
}
bool AC(){
	int v=order[round+1==13?0:round+1];
	bool ff=(round%4==3 && !a.has(v));
	if (ff || 
}
void A();
void D(){
	if (d.n) A();
}
void C(){
	if (c.n) D();
}
void B(){
	if (b.n) C();
}
void A(){
	int v=order[++round==13?round=0:round];
	flag=a.has(v);
	if (!flag) v=a.getmin();
	a.throws(v,1);
	if (BC() || CC() ||DC()) a.eatup();
	if (a.n) B();
}
int main(){
	while (~scanf("%s", s)){
		initial();
	}
    return 0;
}
