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
class VisitALot{
	int dx[4]={1, 0, -1, 0};
	int dy[4]={0, -1, 0, 1};
	char ch[4]={'S', 'W', 'N', 'E'};
public:
	int r, c, a[100][100], dist;
	char ans[10000];
	bool check(int x, int y){
		return !(!x || x>r || !y || y>c || a[x][y]);
	}
	int dfs(int t, int x, int y){
		if (t>dist){
			return 1;
		}
		a[x][y]++;
		for (int i=0;i<4;i++)
			if (check(x+dx[i], y+dy[i])){
				ans[t]=ch[i];
				if (dfs(t+1, x+dx[i], y+dy[i])) return 1;
			}
		a[x][y]--;
		return 0;
	}
	std::string travel(int R, int C, std::vector<int> rx, std::vector<int> ry){
		r=R, c=C;
		dist=(r*c+1)/2;
		int m=rx.size();
		for (int i=0;i<m;i++) a[rx[i]+1][ry[i]+1]=1;
		dfs(2, 1,1);
		std::string res="";
		for (int i=2;i<=dist;i++) res+=ans[i];
		return res;
	}
};
int main(){
	std::cout<<VisitALot().travel(6,5,{1,1,4},{1,3,1})<<std::endl;
	return 0;
}
