#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 500100
using namespace std;
int main(){
	freopen("1.in","w",stdout);
	srand(unsigned(time(NULL)));
	int n=50000;
	for (int i=1;i<=n;i++) printf("%c", 'z'+rand()%1);cout<<endl;
	cout<<20200<<endl;
	int tot=0;
	for (int i=1;i<=20200;i++){
		int tmp=rand()%2;
		if (!tmp) tot++;
		if (tmp || tot>200){
			cout<<"Q ";
			cout<<rand()%n+1<<' '<<rand()%n+1<<endl;
		}
		else{
			cout<<"I ";
			printf("%c ", 'z'+rand()%1);
			cout<<rand()%(tot+n+1)+1<<endl;
		}
	}
	return 0;
}
