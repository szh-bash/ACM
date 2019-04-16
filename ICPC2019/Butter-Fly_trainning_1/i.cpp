#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<ctime>

using std::random_shuffle;

int arr[50];
int result[50];
int count=0;

int print(int n) {
	if (++count>5*n*n) while(1); 
	for (int i = 1; i <= n; i++){
		printf("%d%s",arr[i], (i==n?"\n":" "));
		fflush(stdout);
	} 
	int re;
	scanf("%d",&re);
	if(re==n) exit(0);
	return re;
}

void putfront(int l, int r) {
	int v = arr[r];
	for (int i = r; i > l; i--)
		arr[i] = arr[i-1];
	arr[l] = v;
}

void putback(int l, int r) {
	int v = arr[l];
	for (int i = l; i < r; i++)
		arr[i] = arr[i+1];
	arr[r] = v;
}

void dfs(int n, int l, int r) {
	if (l>=r) return;
	for (int i = l; i <= r; i++) {
		putfront(l,i);
		result[i] = print(n);
		putback(l,i);
	}
	int m = result[l];
	bool have1 = 0;
	for (int i = l; i <= r; i++)
		if (result[i] == m+1) {
			have1 = 1;
			break;
		}
	if (have1) {
		int pos = l-1;
		for (int i = l; i <= r; i++)
			if(result[i] == m+1) putfront(++pos, i);
		dfs(n, l, pos);
		dfs(n, pos+1, r);
	}
	else {
		for (int i = l; i <= r; i++)
			if (result[i] == m) {
				putback(i,r);
				int v=print(n);
				putfront(i,r);
				if(v == m-1) {
					putfront(l,i);
					break;
				}
			}
		dfs(n, l+1, r);
	}
}

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) arr[i] = i;
	dfs(n, 1, n);
	print(n);
	return 0;
}
