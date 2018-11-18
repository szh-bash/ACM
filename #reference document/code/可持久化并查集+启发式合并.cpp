#include<bits/stdc++.h>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define LL long long
#define swap(x,y) (x^y?(x^=y,y^=x,x^=y):0)
#define tc() (A==B&&(B=(A=ff)+fread(ff,1,100000,stdin),A==B)?EOF:*A++)
#define pc(ch) (pp_<100000?pp[pp_++]=(ch):(fwrite(pp,1,100000,stdout),pp[(pp_=0)++]=(ch)))
#define N 200000 
int pp_=0;char ff[100000],*A=ff,*B=ff,pp[100000];
using namespace std;
int n,Q,tot=0,rt[N+5],a[N+5];
struct Chairman_Tree
{
    int Son[2],fa,level;
}node[N*20];
inline void read(int &x)
{
    x=0;int f=1;char ch;
    while(!isdigit(ch=tc())) f=ch^'-'?1:-1;
    while(x=(x<<3)+(x<<1)+ch-'0',isdigit(ch=tc()));
    x*=f;
}
inline void write(int x)
{
    if(x<0) pc('-'),x=-x;
    if(x>9) write(x/10);
    pc(x%10+'0');
}
inline void Build(int &rt,int l,int r)//��ʼ�Ľ�����һ��ʼÿ���ڵ��fa���Ǳ������ǲ��鼯�Ļ���˼��
{
	rt=++tot;
	int mid=l+r>>1;
	if(!(l^r)) {node[rt].fa=l;return;}
	Build(node[rt].Son[0],l,mid),Build(node[rt].Son[1],mid+1,r);
}
inline void NewPoint(int &rt,int lst,int l,int r,int x,int fa)//�²���һ���ڵ�
{
	rt=++tot;
	int mid=l+r>>1;
	if(!(l^r)) {node[rt].fa=fa,node[rt].level=node[lst].level;return;}//����fa����������ǰ�汾������ڵ��level
	node[rt].Son[0]=node[lst].Son[0],node[rt].Son[1]=node[lst].Son[1];
	if(x<=mid) NewPoint(node[rt].Son[0],node[lst].Son[0],l,mid,x,fa);
	else NewPoint(node[rt].Son[1],node[lst].Son[1],mid+1,r,x,fa);
}
inline void Add_level(int rt,int l,int r,int x)//����һ���ڵ���ڰ��Ⱥϲ�ʱ�����ȼ�
{
	int mid=l+r>>1;
	if(!(l^r)) {++node[rt].level;return;}
	if(x<=mid) Add_level(node[rt].Son[0],l,mid,x);
	else Add_level(node[rt].Son[1],mid+1,r,x);
}
inline int Query(int rt,int l,int r,int x)//ѯ��x�ڵ���ĳһ�汾�µ�λ��
{
	int mid=l+r>>1;
	if(!(l^r)) return rt;
	if(x<=mid) return Query(node[rt].Son[0],l,mid,x);
	else return Query(node[rt].Son[1],mid+1,r,x);
}
inline int getfa(int rt,int x)//ѯ��x�ڵ���ĳһ�汾�µ�����
{
	int fa=Query(rt,1,n,x);
	return node[fa].fa^x?getfa(rt,node[fa].fa):fa;//���x�ڵ��ڸð汾�µĸ��׵����������ͷ���x�����򷵻�x�ĸ���������汾�µ����ȣ��;����getfa()�������
}
inline void connect(int v,int x,int y)//�ڰ汾v������x��y�������Ƿ���һ��������
{
	int fx=getfa(rt[v],x),fy=getfa(rt[v],y);//������汾v�����ǵ�����
	if(!(fx^fy)) return;//���������ͬ�����˳�����
	if(node[fx].level<node[fy].level) swap(fx,fy);//���x�����ȼ�С��y�����ȼ����ͽ���x��y
	NewPoint(rt[v],rt[v-1],1,n,node[fy].fa,node[fx].fa);//�����ȼ�С�Ľڵ�ĸ����������ȼ���Ľڵ�ĸ���
	if(!(node[fx].level^node[fy].level)) Add_level(rt[v],1,n,node[fx].fa);//������ǵ����ȼ���ͬ���ͽ����Ǻϲ�������ڵ����ȼ���1
}
int main()
{
    register int i;
    for(read(n),read(Q),Build(rt[0],i=1,n);i<=Q;++i)//�Ƚ�һ������Ȼ����в���
    {
    	int op,x,y;read(op),read(x);
    	if(op^2) read(y),rt[i]=rt[i-1];
    	switch(op)
    	{
    		case 1:connect(i,x,y);break;//�ڵ�ǰ�汾������x��y
    		case 2:rt[i]=rt[x];break;//����ǰ�汾��ԭ�������İ汾x
    		case 3:pc(getfa(rt[i],x)^getfa(rt[i],y)?'0':'1'),pc('\n');break;//����ǰ�汾��x��y�ĸ�����ͬ�����1���������0
		}
    }
    return fwrite(pp,1,pp_,stdout),0;
}

