#include<bits/stdc++.h>

using namespace std;

vector<int> vec = {2, 5, 4, 3, 1};

void bubble_sort() {
    for(int i = 0; i < vec.size(); i++) {
        for(int j = 1; j < vec.size() - i; j++) {
            if(vec[j - 1] > vec[j]) {
                swap(vec[j - 1], vec[j]);
            }
        }
    }
}

int main() {
    bubble_sort();

    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
}