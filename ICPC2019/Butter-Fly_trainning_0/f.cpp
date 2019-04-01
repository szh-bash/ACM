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
#define N 20000
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, m, k;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
struct team{
	char name[20];
	char pro[30][5];
	int a[30], t[30];
	int st;
	int num, tot, last;
}board[N];
map <string, int> mp;
void calc(int id){
	team *p = &board[id];
	p->num=p->tot=p->last=0;
	for (int i=1;i<=n;i++)
		if (p->pro[i][0]=='+')
			p->num++,
			p->tot+=p->t[i]+(p->a[i]-1)*20,
			p->last=max(p->last,p->t[i]); //?????
}
void get(char *s, int id, int st){
	team *p=&board[id];
	strcpy(p->name,s);
	p->st=st;
	for (int i=1;i<=n;i++) scanf("%s%d%d", p->pro[i], &(p->a[i]), &(p->t[i]));
	calc(id);
}
bool cmp(team a, team b){
	if (a.num>b.num) return 1;
	if (a.num<b.num) return 0;
	if (a.tot<b.tot) return 1;
	if (a.tot>b.tot) return 0;
	if (a.last<b.last) return 1;
	if (a.last>b.last) return 0;
	return strcmp(a.name, b.name)<0;
}
int main(){
	n=read();m=read();k=read();
	int cnt=0;
	char s[30];
	for (int i=1;i<=m;i++){
		scanf("%s", s);
		if (mp[s]) get(s,mp[s],0);
		else get(s,mp[s]=++cnt,0);
	}
	for (int i=1;i<=k;i++){
		scanf("%s", s);
		get(s,mp[s],1);
	}
	sort(board+1,board+1+m,cmp);
	int le=m, ri=1;
	for (int i=1;i<=m;i++)
		if (board[i].st) le=min(le,i), ri=max(ri,i);
	for (int i=le;i<=ri;i++)
		if (!board[i].st){
			for (int j=1;j<=n;j++)
				if (board[i].pro[j][0]!='+'){
					board[i].pro[j][0]='+';
					board[i].a[j]++;
					board[i].t[j]=240;
				}
			calc(i);
		}
	sort(board+1,board+1+m,cmp);
	le=m, ri=1;
	for (int i=1;i<=m;i++)
		if (board[i].st) le=min(le,i), ri=max(ri,i);
	if (ri-le+1==k) puts("Leaked");
	else puts("Fake");
    return 0;
}
