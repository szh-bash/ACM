#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
long long a, b, c, tot;
int main(){
	cin>>a>>b>>c;
	if (a>=b && a>=c){
		if (b>=c){
			if (a>b) tot+=a-b-1;
			if (a>c) tot+=a-c-1;
		}
		else{
			if (a>c) tot+=a-c-1;
			tot+=a-b-1;
		}
	}
	else
	if (b>=a && b>=c){
		if (a<b) tot+=b-a-1;
		if (c<b) tot+=b-c-1;
	}
	else
	if (c>=a && c>=b){
		if (a>=b){
			if (a<c) tot+=c-a-1, tot+=c-b-1;
			if (a==c) tot+=c-b-1;
		}
		else{
			tot+=c-a-1;
			if (b<c) tot+=c-b-1;
		}
	}
	cout<<tot<<endl;
	return 0;
}
