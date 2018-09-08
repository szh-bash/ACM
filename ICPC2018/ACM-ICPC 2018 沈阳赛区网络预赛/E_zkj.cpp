#include <bits/stdc++.h>
#define N 350
#define eps 0.000001
using namespace std;
const double pi=acos(-1);

struct node1{double rad;int w;}p[10*N];
int x[N],y[N];
int n,s,R,tot;

double dis(int a,int b)  {return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));}
double dis2(int a,int b) {return ((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));}
bool cmp(node1 a,node1 b) {if (a.rad==b.rad) return a.w>b.w; return a.rad<b.rad;}

int check(int pos,double r)
{
	int sum=0; tot=0;
	for (int i=1;i<=n;i++) if (pos!=i)
	{
		if (x[i]==x[pos]&&y[i]==y[pos]) {sum++; continue;}
		if (dis(i,pos)>r*2) continue;
		double rad1=atan2(y[i]-y[pos],x[i]-x[pos]);
		double h=sqrt(r*r-dis2(i,pos)/4);
		double rad2=asin(h/r);
		double lrad=rad1-rad2,rrad=rad1+rad2;
		if (lrad<0&&rrad<0) lrad+=pi*2,rrad+=pi*2;
		if (lrad>=0&&rrad<=pi*2)
		{
			p[++tot].rad=lrad; p[tot].w=1;
			p[++tot].rad=rrad; p[tot].w=-1;
		}
		else
		{
			p[++tot].rad=lrad+2*pi; p[tot].w=1;
			p[++tot].rad=2*pi;      p[tot].w=-1;
			p[++tot].rad=0;         p[tot].w=1;
			p[++tot].rad=rrad;      p[tot].w=-1;
		}
	}
	if (sum>=s-1) return 1;
	sort(p,p+tot+1,cmp);
	int cnt=sum;
	for (int i=1;i<=tot;i++) 
	{
		cnt+=p[i].w;
		if (cnt>=s-1) return 1;
	}
	return 0;
}

void work()
{
	scanf("%d %d",&n,&s);
	for (int i=1;i<=n;i++) scanf("%d %d",&x[i],&y[i]);
	scanf("%d",&R);
	if (s>n) {puts("The cake is a lie."); return;}
	double l=0,r=40000,mid;
	while (abs(r-l)>eps)
	{
		mid=(l+r)/2; int pd=0;
		for (int i=1;i<=n;i++) if (check(i,mid)==1)
		{
			pd=1; break;
		}
		if (pd==1) r=mid; else l=mid;
	}
	printf("%.4f\n",l+R);
}

int main()
{
	int cas; scanf("%d",&cas);
	for (int i=1;i<=cas;i++) work();
}
