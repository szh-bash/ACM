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
inline void Build(int &rt,int l,int r)//初始的建树，一开始每个节点的fa都是本身，这是并查集的基础思想
{
	rt=++tot;
	int mid=l+r>>1;
	if(!(l^r)) {node[rt].fa=l;return;}
	Build(node[rt].Son[0],l,mid),Build(node[rt].Son[1],mid+1,r);
}
inline void NewPoint(int &rt,int lst,int l,int r,int x,int fa)//新插入一个节点
{
	rt=++tot;
	int mid=l+r>>1;
	if(!(l^r)) {node[rt].fa=fa,node[rt].level=node[lst].level;return;}//更新fa，并复制以前版本的这个节点的level
	node[rt].Son[0]=node[lst].Son[0],node[rt].Son[1]=node[lst].Son[1];
	if(x<=mid) NewPoint(node[rt].Son[0],node[lst].Son[0],l,mid,x,fa);
	else NewPoint(node[rt].Son[1],node[lst].Son[1],mid+1,r,x,fa);
}
inline void Add_level(int rt,int l,int r,int x)//增加一个节点的在按秩合并时的优先级
{
	int mid=l+r>>1;
	if(!(l^r)) {++node[rt].level;return;}
	if(x<=mid) Add_level(node[rt].Son[0],l,mid,x);
	else Add_level(node[rt].Son[1],mid+1,r,x);
}
inline int Query(int rt,int l,int r,int x)//询问x节点在某一版本下的位置
{
	int mid=l+r>>1;
	if(!(l^r)) return rt;
	if(x<=mid) return Query(node[rt].Son[0],l,mid,x);
	else return Query(node[rt].Son[1],mid+1,r,x);
}
inline int getfa(int rt,int x)//询问x节点在某一版本下的祖先
{
	int fa=Query(rt,1,n,x);
	return node[fa].fa^x?getfa(rt,node[fa].fa):fa;//如果x节点在该版本下的父亲等于它本身，就返回x，否则返回x的父亲在这个版本下的祖先，和经典的getfa()函数差不多
}
inline void connect(int v,int x,int y)//在版本v中连接x和y，将他们放入一个集合中
{
	int fx=getfa(rt[v],x),fy=getfa(rt[v],y);//先求出版本v中它们的祖先
	if(!(fx^fy)) return;//如果祖先相同，就退出函数
	if(node[fx].level<node[fy].level) swap(fx,fy);//如果x的优先级小于y的优先级，就交换x和y
	NewPoint(rt[v],rt[v-1],1,n,node[fy].fa,node[fx].fa);//将优先级小的节点的父亲连向优先级大的节点的父亲
	if(!(node[fx].level^node[fy].level)) Add_level(rt[v],1,n,node[fx].fa);//如果它们的优先级相同，就将它们合并后的祖宗的优先级加1
}
int main()
{
    register int i;
    for(read(n),read(Q),Build(rt[0],i=1,n);i<=Q;++i)//先建一棵树，然后进行操作
    {
    	int op,x,y;read(op),read(x);
    	if(op^2) read(y),rt[i]=rt[i-1];
    	switch(op)
    	{
    		case 1:connect(i,x,y);break;//在当前版本下连接x和y
    		case 2:rt[i]=rt[x];break;//将当前版本还原回曾经的版本x
    		case 3:pc(getfa(rt[i],x)^getfa(rt[i],y)?'0':'1'),pc('\n');break;//若当前版本下x和y的父亲相同，输出1，否则输出0
		}
    }
    return fwrite(pp,1,pp_,stdout),0;
}

