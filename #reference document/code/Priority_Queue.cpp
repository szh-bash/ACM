struct node{
	int n, dist;
	node (int n, int dist): n(n), dist(dist){}
	bool operator <(const node &o) const {return this->dist<o.dist;}
	bool operator >(const node &o) const {return this->dist>o.dist;} 
};
//priority_queue<int> qq;//���Ǹ��������ӣ������ 
//typedef pair<int, int> P; 
//priority_queue<P, vector<P>, greater<P> > Q; pair���ֵ���Ƚ� 
priority_queue<node, vector<node>, greater<node> > q;, greater<int> > minHeap; //�洢���ֵ��ֵԽС�����ȼ�Խ��
