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

priority_queue<int, vector<int>, less<int> > maxHeap; //�洢С��ֵ��ֵԽ�����ȼ�Խ��
priority_queue<int, vector<int>, greater<int> > minHeap; //�洢���ֵ��ֵԽС�����ȼ�Խ��
