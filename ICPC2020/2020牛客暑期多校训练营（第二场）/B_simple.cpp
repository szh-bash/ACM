#include<stdio.h>

#include<vector>
#include<map>

using namespace std;

#define eps 1e-12

struct compare
{
	bool operator()(const double &key1,const double &key2)
	{
		if(key1-key2<(-eps)||key1-key2>eps)
		{
			return key1<key2;
		}
		else
		{
			return 0;
		}
	}
};

vector<pair<double,double> > points;

int maxPoints()
{
    int res=1;
    int i;
    for(i=0;i<points.size();++i)
	{
        map<double,int,compare> m;
        int j; 
        for(j=i+1;j<points.size();++j)
		{
            if(points[j].first*points[i].second==points[i].first*points[j].second)
            {
            	continue;
			}
            double dx=points[j].first-points[i].first;
            double dy=points[j].second-points[i].second;
            ++m[dx/dy];
        }
        map<double,int>::iterator it;
        for(it=m.begin();it!=m.end();++it)
		{
            res=max(res,it->second+1);
        }
    }
    return res;
}

int main()
{
	int n;
	scanf("%d",&n);
	double x,y;
	while(n--)
	{
		scanf("%lf%lf",&x,&y);
		double temp=x*x+y*y;
		points.push_back(make_pair(x/temp,y/temp));
	}
	printf("%d\n",maxPoints());
	return 0;
}

