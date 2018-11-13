#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;
#define MAXN    (200)

int n;

char _s1[MAXN], _s2[MAXN];

struct point {
    int g;
    point *next;
};

point *a[MAXN * 2];

void add(int x, int y) {
    point *p = new point;
    p->g = y;
    p->next = a[x];
    a[x] = p;
}

bool check(int x, int y) {
    if (x == y) return true;
    queue<int> _queue;
    _queue.push(x);
    unordered_set<int> _visited;
    _visited.insert(x);

    while (!_queue.empty()) {
        int head = _queue.front();
        for (auto *ptr = a[head]; ptr != nullptr; ptr = ptr->next) {
            if (_visited.find(ptr->g) == _visited.end()) {
                _visited.insert(ptr->g);
                _queue.push(ptr->g);
                if (ptr->g == y) return true;
            }
        }
        _queue.pop();
    }
    return false;
}

void doit() {
    int max_id = 0;
    unordered_map<string, int> id_map;
    auto get_id = [&](const string &name) {
        if (id_map.find(name) == id_map.end()) {
            id_map[name] = ++max_id;
        }
        return id_map[name];
    };

    vector<pair<string, string>> list;
    vector<pair<int, int>> id_list;

    for (int i = 0; i < n; i++) {
        scanf("%s %s", _s1, _s2);
        string s1 = _s1, s2 = _s2;
        list.push_back(make_pair(s1, s2));
        id_list.push_back(make_pair(get_id(s1), get_id(s2)));
    }

    for (int i = 1; i <= max_id; i++) a[i] = nullptr;

    for (int i = 0; i < n; i++) {
        int x = id_list[i].first;
        int y = id_list[i].second;

        if (!check(y, x)) {
            add(x, y);
        } else {
            printf("%s %s\n", list[i].first.c_str(), list[i].second.c_str());
            return;
        }
    }
    printf("0\n");

}

int main() {
    while (~scanf("%d", &n)) {
        doit();
    }
    return 0;
}