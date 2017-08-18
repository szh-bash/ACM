#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
bitset<32> f(0xffffffff);
int main(){
	cout<<0xffffffffffffffffffffffffffffffffff<<endl;
	f[0]=0;
	cout<<f<<endl;
	cout<<f.to_ulong()<<endl;
	cout<<f.to_uint()<<endl;
	return 0;
}

