#include <cstdio>
#include <map>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
map<string, int> g;
int n, m;
int main(){
    g.clear();
    g["abc"]=1;
    cout<<g["dfs"]<<' '<<g["abc"]<<endl;
    return 0;
}
