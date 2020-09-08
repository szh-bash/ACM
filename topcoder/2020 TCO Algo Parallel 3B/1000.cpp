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
int f[200];
class HorseTicket{
	public:
	string getTicket(vector<string> s, ll id){
		int len=s.size();
		for (int i=0;i<len;i++)
			for (int j=0;j<s[i].size();j++)
				f[s[i][j]]=1;
		for (int i=0;i<132;i++) cout<<f[i]<<' ';cout<<endl;
		int pre[200];
		for (int i=1;i<132;i++) pre[i]=pre[i-1]+f[i];
		int sum=pre[131];
		if (pow[sum]<id
		for (int i=1;i<132;i++)
			if (f[i]){
				int res=sum-pre[i];
				if (pow[res]>=id) printf("%c", char(i));
				else id-=pow(res);
			}
	}
};
int main(){
	HorseTicket().getTicket({"A","b"},1);
	return 0;
}
