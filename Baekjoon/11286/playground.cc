#include<bits/stdc++.h>

using namespace std;

struct cmp {
    bool operator() (int a, int b) {
        return a > b;
    }
};

priority_queue<int, vector<int>, cmp> pq;
vector<int> vec;

bool compare(int a, int b) {
    return a < b;
}

int main() {
    for(int i = 0; i < 30; i++) {
        vec.push_back(i);
        pq.push(i);
    }

    sort(vec.begin(), vec.end(), compare);

    for(int i = 0; i < 30; i++) {
        cout << vec[i] << " ";
    }
    cout << "\n";
    
    for(int i = 0; i < 30; i++) {
        cout << pq.top() << " ";
        pq.pop();
    }
}