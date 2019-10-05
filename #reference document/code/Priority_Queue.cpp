struct node{
	int n, dist;
	node (int n, int dist): n(n), dist(dist){}
	bool operator <(const node &o) const {return this->dist<o.dist;}
	bool operator >(const node &o) const {return this->dist>o.dist;} 
};
//priority_queue<int> qq;//这是个大猪蹄子，大根堆 
//typedef pair<int, int> P; 
//priority_queue<P, vector<P>, greater<P> > Q; pair按字典序比较 
priority_queue<node, vector<node>, greater<node> > q;, greater<int> > minHeap; //存储大的值，值越小，优先级越高
