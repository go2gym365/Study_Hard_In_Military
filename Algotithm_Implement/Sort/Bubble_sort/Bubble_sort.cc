#include<bits/stdc++.h>

using namespace std;

vector<int> arr;

void bubbleSort() {
    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr.size() - 1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    bubbleSort();

    for(int a : arr) {
        cout << a << " ";
    }
}