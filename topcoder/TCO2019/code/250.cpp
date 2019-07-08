#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
class LuckyElevator{
	public:
	int actualFloor(int n){
		int ans=n;
		for (int i=1;i<=n;i++){
			int x=i;
			while (x){
				if ((x%10)==4){
					ans--;
					break;
				}
				x/=10;
			}
		}
		return ans;
	}
};
class SaturdayNightStay{
public:
	int countOptions(int firstDay, int firstMonth, int lastDay, int lastMonth){
		int g[]={31,28,31,30,31,30,31,31,30,31,30,31};
		int st=firstDay, ed=lastDay;
		for (int i=0;i<firstMonth-1;i++) st+=g[i];
		for (int i=0;i<lastMonth-1;i++) ed+=g[i];
		int ans=0;
		for (int i=st;i<ed;i++)
			for (int j=i+1;j<=ed;j++){
				//cout<<i<<' '<<j<<endl;
				int x=i%7, y=j%7;
				//if ((x<=y && (j-i>6)) || (x<=5 && 5<y) || (x>y)) ans++;
				for (int k=i;k<j;k++){
					//cout<<k%7<<endl;
					if (k%7==5) {ans++;break;}
				}
			}
		return ans;
	}
};
class TheUnexpectedSwap{
public:
	int findExpectedResult(int digits, string prefN, int seed){
		int mo=1000000007;
		long long ans=0;
		int a[300000];
		a[0]=seed;
		for (int i=1;i<digits;i++) a[i]=(a[i-1]*1009+10009)%100019;
		int len=prefN.length();
		int n[300000];
		for (int i=0;i<len;i++) n[i]=prefN[i]-'0';
		for (int i=len;i<digits;i++) n[i]=n[a[i]%i];
		long long sum=1;
		long long bit[300000];
		bit[digits-1]=1;
		for (int i=digits-2;i>=0;i--) bit[i]=bit[i+1]*10%mo, sum=(sum+bit[i])%mo;
		long long x=1LL*(digits-2)*(digits-1)%mo;
		for (int i=0;i<digits;i++) ans=((ans+2*sum*n[i]+(x-2)*bit[i]%mo*n[i])%mo+mo)%mo;
		return (int)ans;
	}
};
int main(){
	//cout<<SaturdayNightStay().countOptions(1,1,31,12)<<endl;
	cout<<TheUnexpectedSwap().findExpectedResult(10,"1",0);
	return 0;
}

