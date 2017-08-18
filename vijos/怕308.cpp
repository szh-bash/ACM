#include <iostream> 
#define N 100001 
#define min(x,y) x > y ? y : x 
#define max(x,y) x > y ? x : y 

using namespace std;
 typedef long long LL;
 LL a,b,best,ans[N],flag,limt,way[N];
 void dfs(LL x , LL y , LL dep)
 {
 	LL l1,l2,xx,yy,i,j;
 	l1 = max(way[dep - 1] + 1 , y / x);
 	l2 = min(y * (limt -dep + 1) / x , best - 1);
 	for(i = l1 ; i <= l2 ; i ++)
 	{
 		xx = x; yy = y; way[dep] = i;
 		xx = xx * i - yy;
 		if(x < 0) continue;
 		yy = yy * i;
 		if(dep < limt) dfs(xx,yy,dep + 1);
 		if(i < best && xx == 0)
 		{
 			flag = 1 ; best = i;
 			for(j = 1 ; j <= limt ; j ++)ans[j] = way[j];
 		}
 	} 
 }
 int main()
 {
	 cin >> a >> b;
	 flag = 0 ; way[0] = 1 ; best = 99999999;
 	while(flag == 0)
 	{
 		limt++;
 		dfs(a,b,1);
 	}
 	for(LL i = 1; i <= limt ; i ++) cout <<ans[i]<<" ";
 }

