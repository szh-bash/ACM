#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

const int MAX = 1 << 30;
int inter[1000010], com[1000010], f[2][1000010], q[2][1000010], last[2];
int read(){
	char ch=getchar();
	int p=0;
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') 
		p=p*10+ch-'0',ch=getchar();
	return p;
}
int main(){
    int n, m;
    while(scanf("%d%d", &n, &m)!=EOF){
        for (int i = 1; i <= n; i++) inter[i]=read();
        for (int j = 1; j <= m; j++) com[j]=read();
        sort(inter+1,inter+1+n);
        sort(com+1,com+1+m);
        last[0] = 0;int mid=1,l,r;
        for (int i = 1; i <= m; i++){
        	for (;inter[mid]<com[i] && mid<n;mid++);
            r = min(mid + m + 1, n);
            l = max(mid - m - 1, 1);
            int now = i % 2, pre = (i + 1) % 2;
            last[now] = r;
            for (int j = l; j <= r; j++){
            	q[now][j]=i;f[now][j]=MAX;
				if (q[pre][j-1]==i-1)
					f[now][j] = min(f[now][j], f[pre][j - 1] + abs(com[i] - inter[j]));
          	    if(last[pre] < j - 1)
          	      f[now][j] = min(f[now][j], f[pre][last[pre]] + abs(com[i] - inter[j]));
                if (j>l)f[now][j] = min(f[now][j], f[now][j - 1]);
			}
        }
        int ans = MAX;
        for (int i = 0; i <= n; i++) 
		if (q[m%2][i]==m)ans = min(ans, f[m % 2][i]);
        cout<<ans<<endl;
    }
    return 0;
}

