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
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
ll readll(){
    ll p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
#define N 100005
#define BIT 32
int n, a[N];
int mul[N][BIT], nex[N][BIT];
void add(int rt, int x, int y){
	cout<<rt<<' '<<x<<' '<<y<<endl;
}
void data_prepare(){
	for (int i=n;i;i--){
		cout<<"project "<<i<<": "<<endl;
		mul[i][0]=a[i];
		nex[i][0]=i+1;
		for (int j=1;nex[nex[i][j-1]][j-1];j++)
			nex[i][j]=nex[nex[i][j-1]][j-1],
			mul[i][j]=mul[nex[i][j-1]][j-1]&mul[i][j-1];
		add(i,i,a[i]);
		int k=i, sum=a[i];
		while (k<n){
			int j=31;
			while (j>=0 && k<=n){
				while (j>=0 && (sum&mul[k][j])<sum) j--;
				if (j>=0 && (sum&mul[k][j])==sum) k=nex[k][j];
			}
			if (k>n || sum&a[k]==sum) break;
			sum&=a[k];
			add(k,i,sum);
		}
	}
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	data_prepare();
    return 0;
}
