#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAX 500010
#define RANGE 1000000010
using namespace std;
#define max(a,b) ((a) > (b) ? (a):(b))
  
struct SegTree{
    SegTree *son[2];
    int cnt;
      
    SegTree(SegTree *_,SegTree *__,int ___):cnt(___) {
        son[0] = _;
        son[1] = __;
    }
    SegTree() {}
}*_ver[MAX],**ver = _ver + 1;
  
struct Complex{
    int pos,val;
      
    Complex(int _,int __):pos(_),val(__) {}
    Complex() {}
    bool operator <(const Complex &a)const {
        return val < a.val;
    }
}heap[MAX];
int top;
  
int cnt,k,limit_min,limit_max;
int sum[MAX];
  
int now[MAX];
  
SegTree *BuildTree(SegTree *contrast,int l,int r,int x)
{
    if(l == r)  return new SegTree(NULL,NULL,contrast->cnt + 1);
    int mid = (l + r) >> 1;
    if(x <= mid) return new SegTree(BuildTree(contrast->son[0],l,mid,x),contrast->son[1],contrast->cnt + 1);
    return new SegTree(contrast->son[0],BuildTree(contrast->son[1],mid + 1,r,x),contrast->cnt + 1);
}
  
int Kth(SegTree *now,SegTree *contrast,int l,int r,int k)
{
    if(l == r)  return l;
    int mid = (l + r) >> 1;
    if(k <= now->son[0]->cnt - contrast->son[0]->cnt)    return Kth(now->son[0],contrast->son[0],l,mid,k);
    k -= (now->son[0]->cnt - contrast->son[0]->cnt);
    return Kth(now->son[1],contrast->son[1],mid + 1,r,k);
}
  
int main()
{
    cin >> cnt >> k >> limit_min >> limit_max;
    ver[-1] = new SegTree();
    ver[-1]->son[0] = ver[-1]->son[1] = ver[-1];
    ver[0] = BuildTree(ver[-1],-RANGE,RANGE,0);
    for(int i = 1; i <= cnt; ++i) {
        scanf("%d",&sum[i]);    
        sum[i] += sum[i - 1];
        ver[i] = BuildTree(ver[i - 1],-RANGE,RANGE,sum[i]);
    }
    for(int i = limit_min; i <= cnt; ++i) {
        now[i] = 1;
        int _min = Kth(ver[i - limit_min],ver[max(-1,i - limit_max - 1)],-RANGE,RANGE,1);
        heap[++top] = Complex(i,sum[i] - _min);
    }
    make_heap(heap + 1,heap + top + 1);
    long long ans = 0;
    for(int i = 1; i <= k; ++i) {
        pop_heap(heap + 1,heap + top + 1);
        Complex temp = heap[top--];
        ans += temp.val;
        int r = temp.pos - limit_min,l = max(0,temp.pos - limit_max);
        if(++now[temp.pos] > r - l + 1)
            continue;
        int _min = Kth(ver[r],ver[l - 1],-RANGE,RANGE,now[temp.pos]);
        heap[++top] = Complex(temp.pos,sum[temp.pos] - _min);
        push_heap(heap + 1,heap + top + 1);
    }
    cout << ans << endl;
    return 0;
}
