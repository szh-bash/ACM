#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
#define N 1000
#define mo 1000000007
#define num(x) ((x)>='0' && (x)<='9')
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
using namespace std::tr1;
int rou, target, flag, ct;
char s[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (!num(ch)) 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (num(ch)) p=p*10+ch-'0', ch=getchar(); 
	return p*q;
}
int getnext(int p){
	if (p<10) return p+1;
	if (p==10) return 'J';
	if (p=='J') return 'Q';
	if (p=='Q') return 'K';
	if (p=='K') return 'A';
	if (p=='A') return 2;
}
int getnextle(int p){
	if (p<9) return p+1;
	if (p==9) return 'A';
	if (p==10) return 2;
	if (p=='A') return 'J';
	if (p=='J') return 'K';
	if (p=='K') return 'Q';
	if (p=='Q') return 10;
}
struct card{
	int num;
	char ch;
};
class Table{
	public:
		int n;
		int num[100];
		int card[100];
/*		void person(void){
			gets(s);
			persons(s);
		}
		void persons(char s[]){
			n=0;
			for (int i=0;i<100;i++) num[i]=0;
			int len=strlen(s), p=0;
			for (int i=0;i<=len;i++){
				if (num(s[i])) p=p*10+s[i]-'0';
				else
					if (!s[i] || s[i]==' '){
						n++;
						if (!p)
							num[s[i-1]]++,
							card[n]=s[i-1];
						else
							num[p]++,
							card[n]=p;
						p=0;
					}
			}
		}*/
		void reset(void){
			n=0;
			for (int i=0;i<100;i++) num[i]=0;
		}
		void print(void){
			if (n==0) printf("WINNER\n");
			else{
				for (int i=1;i<=n;i++)
					if (card[i]<=10) printf("%d ", card[i]);
					else printf("%c ", card[i]);
				puts("");
			}
		}
		void insert(int p, int q){
			for (int i=1;i<=q;i++)
				card[++n]=p,
				num[p]++;
		}
};
Table e;
class Person{
	public:
		int n;
		int num[100];
		int card[100];
		void person(void){
			scanf("%s", s);
			persons(s);
		}
		void persons(char s[]){
			//cout<<s<<endl;
			//n=0;
			//for (int i=0;i<100;i++) num[i]=0;
			reset();
/*			int len=strlen(s), p=0;
			if (len==0) return;
			for (int i=0;i<=len;i++){
				if (num(s[i])) p=p*10+s[i]-'0';
				else
					if (!s[i] || s[i]==' '){
						n++;
						if (!p)
							num[s[i-1]]++,
							card[n]=s[i-1];
						else
							num[p]++,
							card[n]=p;
						p=0;
					}
			}*/
			//print();
			n=13;
			if (s[1]) num[10]++, card[1]=10;
			else if (num(s[0])) num[s[0]-'0']++, card[1]=s[0]-'0';
			else num[s[0]]++, card[1]=s[0];
			for (int i=2;i<=n;i++){
				scanf("%s", s);
				if (s[1]) num[10]++, card[i]=10;
				else if (num(s[0])) num[s[0]-'0']++, card[i]=s[0]-'0';
				else num[s[0]]++, card[i]=s[0];
			}
		}
		void reset(void){
			n=0;
			for (int i=0;i<100;i++) num[i]=0;
		}
		void print(void){
			if (n==0) printf("WINNER\n");
			else{
				int v='A';
		/*		for (int i=1;i<=n;i++)
					if (card[i]<=10) printf("%d ", card[i]);
					else printf("%c ", card[i]);*/
				do{
					for (int j=1;j<=num[v];j++)
						if (v<=10) printf("%d ",v);
						else printf("%c ", v);
					v=getnext(v);
				}while (v!='A');
				puts("");
			}
		}
		void eatup(void){
			for (int i=1;i<=e.n;i++){
				card[++n]=e.card[i],
				num[e.card[i]]++;
			}
			e.reset();
		}
		void insert(int p, int q){
			for (int i=1;i<=q;i++)
				card[++n]=p,
				num[p]++;
		}
};
Person a;
Person b;
Person c;
Person d;
int order[]={'A',2,3,4,5,6,7,8,9,10,'J','Q','K'};
void init(){
	a.persons(s);
	b.person();
	c.person();
	d.person();
	e.reset();
}
void print(){
	a.print();
//	for (int i=1;i<=a.n;i++) printf("%d ", a.card[i]);cout<<' '<<"test"<<endl;
	b.print();
	c.print();
	d.print();
}
bool AC(){
	if (!e.n) return 0;
	int tv=target+1==13?0:target+1;
	bool ff=rou%4==0 && !a.num[order[tv]];
	if (ff || ct+a.num[order[target]]>4){
		if (flag){
			a.eatup();
			return 0;
		}
		else return 1;
	}
	return 0;
}
bool BC(){
	if (!e.n) return 0;
	int tv=target+1==13?0:target+1;
	bool ff=rou%4==1 && !b.num[order[tv]];
	if (!ff) return 0;
	if (flag) b.eatup();
	return !flag;
}
bool CC(){
	if (!e.n) return 0;
	int tv=target+1==13?0:target+1;
	if (c.num[order[target]]==4){
		if (flag) c.eatup();
		return !flag;
	}
	return 0;
}
bool DC(int p){
	if (!e.n) return 0;
	if (p) return 0;
	if (flag) d.eatup();
	return !flag;
}
void A();
void B();
void C();
void D();
void A(){
	rou++;
	int v=order[target];
	flag=a.num[v]>0;
	if (!a.num[v]){
		v=10;
		while (!a.num[v]) v=getnextle(v);
	}
	ct=1;
	e.insert(v,1);
	for (int i=1;i<=a.n;)
		if (a.card[i]==v){
			a.card[i]=a.card[a.n--];
			break;
		}
		else i++;
	a.num[v]=a.num[v]-1;
	if (BC()) a.eatup();
	else if (CC()) a.eatup();
   	else if (DC(a.n)) a.eatup();
	target++;
	if (target==13) target=0;
	//cout<<rou<<endl;
	//cout<<"A"<<' ';e.print();
	if (a.n) B();
}
void B(){
	rou++;
	int v=order[target];
	flag=b.num[v]>0;
	if (!b.num[v]){
		v=10;
		while (!b.num[v]) v=getnextle(v);
		//flag=0;
	}
	ct=flag?b.num[v]:1;
	e.insert(v,flag?b.num[v]:1);
	for (int i=1;i<=b.n;)
		if (b.card[i]==v){
			b.card[i]=b.card[b.n--];
			if (!flag) break;
		}
		else i++;
	b.num[v]=flag?0:b.num[v]-1;
	if (CC()) b.eatup();
    else if(DC(b.n)) b.eatup();
    else if(AC()) b.eatup();
	target++;
	if (target==13) target=0;
	//cout<<"B"<<' ';e.print();
	if (b.n) C();
}
void C(){
	rou++;
	int v=order[target];
	flag=c.num[v]>0;
	if (!c.num[v]){
		v=10;
		int tv, tmp=1000;
		do{
			if (c.num[v] && c.num[v]<tmp) tmp=c.num[v], tv=v;
			v=getnextle(v);
		}while (v!=10);
		v=tv;
	}
	ct=c.num[v];
	e.insert(v,c.num[v]);
	for (int i=1;i<=c.n;)
		if (c.card[i]==v) c.card[i]=c.card[c.n--];
		else i++;
	c.num[v]=0;
	if (DC(c.n)) c.eatup();
    else if(AC()) c.eatup();
    else if(BC()) c.eatup();
	target++;
	if (target==13) target=0;
	//cout<<"C"<<' ';e.print();
	if (c.n) D();
}
void D(){
	rou++;
	int v=order[target];
	flag=d.num[v]>2;
	if (!flag){
		if (d.num[v]){
			e.insert(v,d.num[v]);
			for (int i=1;i<=d.n;)
				if (d.card[i]==v) d.card[i]=d.card[d.n--];
				else i++;
			ct=d.num[v];
			d.num[v]=0;
		}else ct=0;
//		cout<<"done"<<endl;
		v=10;
		do{
//			cout<<v<<' '<<d.num[v]<<endl;
			if (d.num[v]) break;
			v=getnextle(v);
		}while (v!='Q');
		if (d.num[v]){
			e.insert(v,1);
			for (int i=1;i<=d.n;)
				if (d.card[i]==v){
					d.card[i]=d.card[d.n--];
					break;
				}
				else i++;
			ct++;
			d.num[v]--;
		}
		else flag=1;
	}
	else{
		ct=d.num[v];
		e.insert(v,d.num[v]);
		for (int i=1;i<=d.n;)
			if (d.card[i]==v){
				d.card[i]=d.card[d.n--];
			}
			else i++;
		d.num[v]=0;
	}
//	cout<<"lyk"<<endl;
	if (AC()) d.eatup();
    else if(BC()) d.eatup();
    else if(CC()) d.eatup();
	target++;
	if (target==13) target=0;
	//cout<<"D"<<' ';e.print();
	if (d.n) A();
}
int main(){
	while (~scanf("%s", s)){
		rou=target=0;
		init();
		//cout<<a.n<<' '<<b.n<<' '<<c.n<<' '<<d.n<<' 'endl;
//		if (a.n+b.n+c.n+d.n!=52) break;
		//e.print();
		A();
		//cout<<"Lyk said down"<<endl;
		print();
	}
	return 0;
}
