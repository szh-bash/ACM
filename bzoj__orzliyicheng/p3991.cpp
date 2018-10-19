#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int read(){
    int p=0, q=-1;
    char ch=getchar();
    while (!num(ch)) (ch=='-'?q=-1:0), ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
    return 0;
}