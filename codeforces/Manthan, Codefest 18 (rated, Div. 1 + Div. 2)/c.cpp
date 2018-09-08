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
#define N 2000000
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
char s0[N], s1[N];
int n, ans;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	n=read();
	scanf("%s%s", s0, s1);
	for (int i=0;i<n;i++)
		if (s0[i]!=s1[i]){
			if (i+1<n && s0[i+1]==s1[i] && s0[i+1]!=s1[i+1]) swap(s0[i],s0[i+1]), ans++;
			else ans++;
		}
	cout<<ans<<endl;
    return 0;
}
