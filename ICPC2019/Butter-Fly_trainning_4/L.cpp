#include<bits/stdc++.h>//���
using namespace std;
typedef unsigned long long ll;
const int INF=0x3f;
char dp[900000000];//������仯�Ǹ���ǰ��n�õ�
int a[110];
ll get_s(int n){
    ll s=0;
    for(int i=1; i<=n; i++) s=s*3+a[i];//���״̬��Ψһ�ģ����Ǻ��治ͬ��ö�ٿ��ܻ��ظ��õ����״̬
    return s;
}
bool check(int n){
    for(int i=3; i<=n; i++)
        if(a[i]==1 && a[i-1]==2 && a[i-2]==1)
            return true;
    return false;
}
void show(int n){
    for(int i=1; i<=n; i++)
        printf("%d ", a[i]);
    puts("");
}
int dfs(int n,int cnt){
	//show(cnt);
    ll s=get_s(n);//��ǰ���̵�״̬
    char &ret=dp[s];
    if(ret^INF)	return ret;
    if(check(n)) return ret=-1;
    if(cnt==n) return ret=0;
    bool ok=true;
    for(int i=1; i<=n; i++){//��ǰ���λ����1/2�� ��ôö��֮����������ʲô�������ˣ��ͻ�ȥö�ٺ�����
        if(a[i]==0){
            for(int j=1; j<=2; j++){
                a[i]=j;
                int t=dfs(n, cnt+1);
                a[i]=0;
                if(t==-1) return ret=1;//������ڱذ�̬��һ����ʤ����
                if(t==0) ok=false;//����û�бذ�̬������ƽ��
            }
        }
    }
    return ret=ok?-1:0;//����ƽ�ֶ�û��
}
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p; 
}
int main(){
	for (int _=read(), o=1;_;_--, o++){
		int n=read();
		printf("Case #%d: ", o);
		if(n<7) printf("Draw");
		else if (n&1) printf("Panda");
		else if (n<16) printf("Draw");
		else printf("Sheep");
		puts("");
	}
	return 0; 
    for(int i=1;i<30; i++){
		memset(dp, 0x3f, sizeof dp);
        memset(a, 0, sizeof a);
        printf("%d: %d\n", i, dfs(i, 0));
    }
    return 0;
}
