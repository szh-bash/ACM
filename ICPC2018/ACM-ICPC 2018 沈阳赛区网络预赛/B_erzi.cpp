#include<bits/stdc++.h>
#define ll long long

using namespace std;
struct tt{ll l,r;};

tt operator-(tt a){
	return {-a.r,-a.l};
}
tt operator-(tt a,tt b){
	return {a.l-b.r,a.r-b.l};
}
tt operator+(tt a,tt b){
	return {a.l+b.l,a.r+b.r};
}
tt operator*(tt a,tt b){
	ll t1=a.l*b.l,t2=a.l*b.r,t3=a.r*b.l,t4=a.r*b.r;
	return {min(min(t1,t2),min(t3,t4)),max(max(t1,t2),max(t3,t4))};
}
tt operator^(tt a,tt b){
	tt ans;
	if (a.l<0) ans.l=0; else ans.l=a.l;
	ans.r=a.r*b.r;
	return ans;
}

char s[100000];

tt E(int l,int r);
tt F(int l,int r);
tt T(int l,int r);
tt D(int l,int r);
tt N(int l,int r);

tt E(int l,int r){
	int kh=0;
	for (int i=r;i>=l;i--){
		if (s[i]==')')kh++;
		if (s[i]=='(')kh--;
		if (kh==0&&s[i]=='+'){
			return E(l,i-1)+T(i+1,r);
		}
		if (kh==0&&s[i]=='-'&&i!=1&&s[i-1]!='-'&&s[i-1]!='+'&&s[i-1]!='*'&&s[i-1]!='('){
			return E(l,i-1)-T(i+1,r);
		}
	}
	return T(l,r);
}

tt T(int l,int r){
	int kh=0;
	for (int i=l;i<=r;i++){
		if (s[i]=='(')kh++;
		if (s[i]==')')kh--;
		if (kh==0&&s[i]=='*'){
			return F(l,i-1)*T(i+1,r);
		}
	}
	return F(l,r);
}

tt F(int l,int r){
	int kh=0;
	for (int i=l;i<=r;i++){
		if (s[i]=='(')kh++;
		if (s[i]==')')kh--;	
		if (kh==0&&s[i]=='d'){
			return D(l,i-1)^F(i+1,r);
		}
	}
	return D(l,r);
}

tt D(int l,int r){
	if (s[l]=='-') return -D(l+1,r);
	if (s[l]=='(') return E(l+1,r-1);
	return N(l,r);
}

tt N(int l,int r){
	ll ans=0;
	for (int i=l;i<=r;i++)
	ans=ans*10+s[i]-'0';
	return {ans,ans};
}

int main(){
	while(~scanf("%s",s+1)){
		int len=strlen(s+1);
		tt ans=E(1,len);
		printf("%lld %lld\n",ans.l,ans.r);
	}
}
