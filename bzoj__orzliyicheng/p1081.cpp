#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define Rep(i, n) for(int i=1;i<=n;i++)
using namespace std;
const int N = 20;
int Dat[N], Base[N], Sum;
int n, m;

inline void Input() {
	scanf("%d%d", &n, &m);
	Sum = 1;
	Rep(i, n) Sum *= m, Base[i] = 1;
}

inline void Write() {
	Sum--;
	Rep(i, n) printf("%c", Dat[i] < 10 ? '0' + Dat[i] : 'A' + Dat[i] - 10);
	printf("\n");
}
inline void Solve() {
	Write();
	while(Sum) {
		Rep(i, n)
			if(Dat[i] + Base[i] > -1 && Dat[i] + Base[i] < m) {
				Dat[i] += Base[i];
				break;
			} else Base[i] *= -1;
		Write();
	}
}

int main() {
	Input();
	Solve();
	return 0;
}
