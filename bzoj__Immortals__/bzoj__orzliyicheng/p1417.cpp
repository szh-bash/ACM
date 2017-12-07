#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
const int mod = 10007;
using namespace std;
struct zsm{
	int xs, x[31];
	double exp;
	void clear(){
		memset(x,0,sizeof(x));
		xs=0;
	}
	bool operator==(zsm &a){
		for (int i=0;i<31;i++)
			if (a.x[i]!=x[i])
			return 0;
		return 1;
	}
	void sort(){std::sort(x,x+31);}
	unsigned int hash(){
		unsigned int hash=0, seed=131;
		for (int i=30;i>=0 && x[i];i--) hash=hash*seed+x[i];
		return hash % mod;
	}
};
vector<zsm> hh[mod];
double search(zsm &a){
	unsigned int x=a.hash();
	for (int i=0;i!=hh[x].size();i++)
		if (a==hh[x][i]) return hh[x][i].exp;
	return -1;
}
int n, m, fa[31], s[31];
int father(int t){return fa[t]==t?t:fa[t]=father(fa[t]);}
double dp(zsm ost){
	if (ost.xs==1) return 0;
	double x=search(ost);
	if (x!=-1.0) return x;
	double tmp=0, ans=0;
    for(int i = 0; i != 31; i ++)
		tmp+=ost.x[i]*(ost.x[i]-1)/2;
	for (int i=0;i<31;i++)
		if (ost.x[i])
		for (int j=i+1;j<31;j++)
			if (ost.x[j]){
				zsm sst=ost;
				sst.x[i]+=sst.x[j];
				sst.x[j]=0;
				sst.xs--;
				sst.sort();
				ans+=ost.x[i]*ost.x[j]*dp(sst);
			}
	ans=(ans/(n*(n-1)/2)+1)/(1-tmp/(n*(n-1)/2));
	ost.exp=ans;
	hh[ost.hash()].push_back(ost);
	return ans;
}
int main(){
    scanf("%d%d", &n, &m);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++){
		int x, y;
        scanf("%d%d", &x, &y);
		fa[father(x)]=father(y);
	}
	for (int i=1;i<=n;i++)	s[father(i)]++;
	zsm st;
	st.clear();
	for (int i=1;i<=n;i++) 
		if (s[i]) st.x[st.xs++]=s[i];
	st.sort();
	printf("%.6lf\n", dp(st));
	return 0;
}
