#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define M 50500
#define BASE 151
using namespace std;
typedef unsigned long long ll;
struct abcd{
	abcd *fa,*ls,*rs;
	int val,size;
	ll hash;
	abcd(int x);
	void Push_Up();
}*null=new abcd(0),*root=null,*tree[M];
int n,m;
char s[M];
ll power[M];
abcd :: abcd(int x)
{
	fa=ls=rs=null;
	hash=val=x;
	size=(bool)x;
}
void abcd :: Push_Up()
{
	size=ls->size+rs->size+1;
	hash=ls->hash*power[rs->size+1]+val*power[rs->size]+rs->hash;
}
void Zig(abcd *x)
{
	abcd *y=x->fa;
	y->ls=x->rs;
	x->rs->fa=y;
	x->rs=y;
	x->fa=y->fa;
	if(y==y->fa->ls)
		y->fa->ls=x;
	else
		y->fa->rs=x;
	y->fa=x;
	y->Push_Up();
	if(y==root)
		root=x;
}
void Zag(abcd *x)
{
	abcd *y=x->fa;
	y->rs=x->ls;
	x->ls->fa=y;
	x->ls=y;
	x->fa=y->fa;
	if(y==y->fa->ls)
		y->fa->ls=x;
	else
		y->fa->rs=x;
	y->fa=x;
	y->Push_Up();
	if(y==root)
		root=x;
}
void Splay(abcd *x,abcd *aim)
{
	while(1)
	{
		abcd *y=x->fa,*z=y->fa;
		if(y==aim)
			break;
		if(z==aim)
		{
			if(x==y->ls)
				Zig(x);
			else
				Zag(x);
			break;
		}
		if(x==y->ls)
		{
			if(y==z->ls)
				Zig(y);
			Zig(x);
		}
		else
		{
			if(y==x->rs)
				Zag(y);
			Zag(x);
		}
	}
	x->Push_Up();
}
void Find(abcd *x,int y,abcd *z)
{
	while(1)
	{
		if(y<=x->ls->size)
			x=x->ls;
		else
		{
			y-=x->ls->size;
			if(y==1)
				break;
			y--;x=x->rs;
		}
	}
	Splay(x,z);
}
void Insert(int pos,int x)
{
	Find(root,pos,null);
	Find(root,pos+1,root);
	(root->rs->ls=new abcd(x))->fa=root->rs;
	root->rs->Push_Up();
	root->Push_Up();
}
abcd* Build_Tree(int x,int y)
{
	if(x>y) return null;
	int mid=x+y>>1;
	abcd *re=new abcd(s[mid]);
	tree[mid]=re;
	(re->ls=Build_Tree(x,mid-1))->fa=re;
	(re->rs=Build_Tree(mid+1,y))->fa=re;
	return re->Push_Up(),re;
}
void Output(abcd *x)
{
	if(x==null)
		return ;
	Output(x->ls);
	printf("----------------------%c\n",x->val);
	Output(x->rs);
}
bool Check(int x,int y,int mid)
{
	Find(root,x,null);
	Find(root,x+mid+1,root);
	ll hash1=root->rs->ls->hash;
	Find(root,y,null);
	Find(root,y+mid+1,root);
	ll hash2=root->rs->ls->hash;
	return hash1==hash2;
}
int Bisection(int x,int y)
{
	int l=0,r=min(n-x+1,n-y+1);
	while(l+1<r)
	{
		int mid=l+r>>1;
		if( Check(x,y,mid) )
			l=mid;
		else
			r=mid;
	}
	if( Check(x,y,r) )
		return r;
	else
		return l;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("std.out","w",stdout);
	int i,x,y;
	char p[10];

	for(power[0]=1,i=1;i<M;i++)
		power[i]=power[i-1]*BASE;

	scanf("%s",s+1);n=strlen(s+1);

	root=new abcd(19980402);
	(root->rs=new abcd(19980402))->fa=root;
	(root->rs->ls=Build_Tree(1,n))->fa=root->rs;
	root->rs->Push_Up();
	root->Push_Up();

	cin>>m;
	for(i=1;i<=m;i++)
	{
		scanf("%s",p);
		if(p[0]=='Q')
		{
			scanf("%d%d",&x,&y);
			Splay(tree[x],null);x=root->ls->size;
			Splay(tree[y],null);y=root->ls->size;
			printf("%d\n", Bisection(x,y) );
		}
		else
		{
			scanf("%s%d",p,&x);
			if(x>n) x=n+1;
			Insert(x,p[0]);
			n++;
		}
		//Output(root);
	}
	return 0;
}

