#include <list>
#include <cstdio>
#include <iostream>
using namespace std;
int n, h[100001], ans[100001];
int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", &h[i]);
    h[0]=9999999;
    list<int> l;
    l.clear();
    l.push_back(0);
    for (int i=n;i>0;i--){
        while (h[l.back()] <= h[i]) l.pop_back();
        ans[i] = l.back();
        l.push_back(i);
    }
    for (int i=1;i<=n;i++) printf("%d\n", ans[i]);
}
