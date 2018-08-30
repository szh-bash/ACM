class Student
{
    int id;
    char name[20];
    bool gender;
    bool operator < (Student &a) const
    {
        return id > a.id;
    }
};

priority_queue<int, vector<int>, less<int> > maxHeap; //存储小的值，值越大，优先级越高
priority_queue<int, vector<int>, greater<int> > minHeap; //存储大的值，值越小，优先级越高
