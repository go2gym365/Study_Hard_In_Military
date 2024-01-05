#include<bits/stdc++.h>

using namespace std;

vector<int> arr;

void Print() {
    for(int a : arr) {
        cout << a << " ";
    }
    cout << "\n";
}

void selectionSort() {
    clock_t start, finish;
    double duration;
    
    start = clock();

    for(int i = 0; i < arr.size(); i++) {
        int minValueIdx = i;
        for(int j = i+1; j < arr.size(); j++) {
            if(arr[minValueIdx] > arr[j]) {
                minValueIdx = j;
            }
        }
        if(minValueIdx != i) {
            swap(arr[i], arr[minValueIdx]);
        }
    }

    finish = clock();
    
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    Print();
    cout << duration << "초" << "\n";
}

int main() {
    
    for(int i = 0; i < 2500; i++) {
        arr.push_back(rand() % 100);
    }

    selectionSort();
}