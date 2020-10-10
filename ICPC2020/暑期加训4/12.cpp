#include<bits/stdc++.h>
using namespace std;
const int maxn=50;

int len;
int a[maxn];
int b[maxn];
int kk[maxn];
int ww[maxn];
long long f[maxn][2][2][2][2][2];

long long work(long long A,long long B,long long K,long long W){
	memset(f,0,sizeof(f));
	len=40;
	for(int i=0;i<=len;++i)
		a[i]=(A>>i)&1, 
		b[i]=(B>>i)&1,
		kk[i]=(K>>i)&1,
		ww[i]=(W>>i)&1;
	
	f[len][1][1][1][1][1]=1;
	for(int i=len;i>0;--i)
		for(int p=0;p<2;++p)
			for(int q=0;q<2;++q)
				for(int det=0;det<2;++det)
					for(int big=0;big<2;++big)
						for(int xr=0;xr<2;++xr){
							if(!f[i][p][q][det][big][xr])continue;
							for(int x=0;x<2;++x){
								for(int y=0;y<2;++y){
									int np=0,nq=0,ndet=0,nbig=0,nxr=0;
									
									if(p==1&&x>a[i-1]) continue;
									else if(p==1&&x==a[i-1]) np=1;
									else np=0;
									
									if(q==1&&y>b[i-1]) continue;
									else if(q==1&&y==b[i-1]) nq=1;
									else nq=0;
									
									if(det==1&&x-y>kk[i-1]) continue;
									else if(det==1&&x-y==kk[i-1]) ndet=1;
									else ndet=0;
									
									if(big==1&&x<y) continue;
									else if(big==1&&x==y) nbig=1;
									else nbig=0;
									
									if(xr==1&&(x^y)>ww[i-1]) continue;
									else if(xr==1&&(x^y)==ww[i-1]) nxr=1;
									else nxr=0;
									
									f[i-1][np][nq][ndet][nbig][nxr]+=
										f[i][p][q][det][big][xr];
								}
							}
						}
	long long ret=0;
	for(int p=0;p<2;++p)
		for(int q=0;q<2;++q)
			for(int det=0;det<2;++det)
				for(int big=0;big<2;++big)
					for(int xr=0;xr<2;++xr)
						ret+=f[0][p][q][det][big][xr];
	return ret;
}

int main(){
	int T;cin>>T;
	while(T--){
		int A,B,K,W;
		cin>>A>>B>>K>>W;
		int ans=0;
//		for(int i=0;i<=A;++i){
//			for(int j=0;j<=i;++j){
//				if(abs(i-j)<=K&&(i^j)<=W){
//					if(i<A&&j<B&&i==j&&i-j<K&&(i^j)<W){
//						cout<<"A "<<i<<' '<<j<<endl;
//					}
//				}
//			}
//		}
//		cout<<"! "<<ans<<endl;
		cout<<(work(A,B,K,W)+work(B,A,K,W)-min(A+1,B+1))<<endl;
	}
	return 0;
}
