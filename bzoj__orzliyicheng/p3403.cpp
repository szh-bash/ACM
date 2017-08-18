#include <list>
#include <cstdio>
using namespace std;
list <int> queue;
int main(){
    int s, k, cnt=0;
    scanf("%d", &s);
    getchar();
    queue.clear();
    for (int i=1;i<=s;i++){
        char a, b, c;
        a=getchar();
        b=getchar();
        c=getchar();
        if (a=='A'){
            ++cnt;
            if (c=='L') queue.push_front(cnt);
            else queue.push_back(cnt);
            getchar();
        }
        else{
            scanf("%d", &k);
            while (k){
                if (c=='L') queue.pop_front();else queue.pop_back();
                k--;
            }
            getchar();
        }
    }
    while (!queue.empty()){
        printf("%d\n", queue.front());
        queue.pop_front();
    }
    return 0;
}
