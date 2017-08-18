#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
 
#define MAXN 500000
#define MAXM 500000
#define MIN(a,b) ((a)<(b)?(a):(b))

using namespace std;

struct Link{Link* next;int to;};
 
int N,M;
Link* link[MAXN];
int money[MAXN];
int S,P;
bool isBar[MAXN];
int belong[MAXN];

void insert(int u,int v)
{
     static int pool_counter;
     static Link pool[MAXM*4];
     pool[pool_counter].to=v;
     pool[pool_counter].next=link[u];
     link[u]=&pool[pool_counter++];
}
void tarjan(int start)
{
     static int DFN[MAXN];
     static int LOW[MAXN];
     static int stamp;
     static int stack[MAXN];
     static bool instack[MAXN];
     static int top;
     static bool visited[MAXN];
    
     static int depth;
     static Link* i[MAXN];
     static int root[MAXN];
    
     i[depth]=link[root[depth]=start];
     DFN[root[depth]]=LOW[root[depth]]=++stamp;
     instack[stack[top++]=root[depth]]=true;
     visited[root[depth]]=true;
    
     do
     {
       if (i[depth])
       {
          if (!visited[i[depth]->to])
          {
             i[depth+1]=link[root[depth+1]=i[depth]->to];
             DFN[root[depth+1]]=LOW[root[depth+1]]=++stamp;
             instack[stack[top++]=root[depth+1]]=true;
             visited[root[depth+1]]=true;
             i[depth]=i[depth]->next;
             depth++;
          }
          else if (instack[i[depth]->to])
          {
              LOW[root[depth]]=MIN(LOW[root[depth]],DFN[i[depth]->to]);
              i[depth]=i[depth]->next;
          }
          else i[depth]=i[depth]->next;
       }
       else
       {
           if (LOW[root[depth]]==DFN[root[depth]])
           {       
              do
              {
                instack[stack[--top]]=false;
                if (isBar[stack[top]])
                   isBar[root[depth]]=true;
                if (stack[top]!=root[depth])
                   money[root[depth]]+=money[stack[top]];
                belong[stack[top]]=root[depth];
                for (Link* j=link[stack[top]];j!=0;j=j->next)
                    insert(root[depth],j->to);
              }
              while (stack[top]!=root[depth]);
           }
           if (depth>0)
              LOW[root[depth-1]]=MIN(LOW[root[depth-1]],LOW[root[depth]]);
           depth--;
       }
     }
     while (depth>=0);
}
int DP(int start)
{
    static bool calced[MAXN];
    static int MAX[MAXN];
    start=belong[start];
    if (!calced[start])
    {
       calced[start]=true;      
       for (Link* i=link[start];i!=0;i=i->next)
           if (MAX[start]<DP(i->to))
                  MAX[start]=DP(i->to);
       if (MAX[start]) MAX[start]+=money[start];
       else if (isBar[start]) MAX[start]=money[start];
    }
    return MAX[start];
}

 
int main()
{
    scanf("%d %d",&N,&M);
    for (int i=0;i<M;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        insert(u-1,v-1);
    }
    for (int i=0;i<N;i++)
        scanf("%d",&money[i]);
    scanf("%d %d",&S,&P);
    for (int i=0;i<P;i++)
    {
        int pos;
        if (i+1!=P) scanf("%d ",&pos);
        else scanf("%d",&pos);
        isBar[pos-1]=true;
    }
    tarjan(S-1);
    printf("%d\n",DP(S-1));
    return 0;
}
 
