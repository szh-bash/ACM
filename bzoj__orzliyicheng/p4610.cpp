#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, k, ans,son[300][100][3], v[300][100];
int size[300][100], cnt[100], l1[100], l2[100], root[100];
void add(int m, int x, int &t){
	if (!t){
		t=++cnt[m];
		v[m][t]=x;
		size[m][t]=1;
		return;
	}
	if (v[m][t]<x) add(m,x,son[m][t][0]);
	else add(m,x,son[m][t][1]);
	size[m][t]++;
}
bool check(int x, int y){
	int s=1, t=1, flag=1;
	l1[1]=l2[1]=1;
	while (t<=s){
		if (size[x][l1[t]]!=size[y][l2[t]]){
			flag=0;
			break;
		}
		if (!l1[t] && !l2[t]){
			++t;
			continue;
		}
		l1[++s]=son[x][l1[t]][0];
		l2[s]=son[y][l2[t]][0];
		l1[++s]=son[x][l1[t]][1];
		l2[s]=son[y][l2[t]][1];
		t++;
	}
	return flag;
}
int main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		int x, flag=1;
		for (int j=1;j<=k;j++){
			scanf("%d", &x);
			add(i,x,root[i]);
		}
		for (int j=1;j<i;j++)
			if (check(j,i)){
				flag=0;
				break;
			}
		ans+=flag;
	}
	printf("%d", ans);
	return 0;
}
