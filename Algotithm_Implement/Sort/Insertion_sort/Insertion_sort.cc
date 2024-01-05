#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

void Print() {
    for (int a : arr) {
        cout << a << " ";
    }
    cout << "\n";
}

void Insertion_sort() {
    clock_t start, finish;
    double duration;

    start = clock();

    for (int i = 1; i < arr.size(); i++) {
        int target = arr[i];
        int j = i - 1;
        
        while(j >= 0 && arr[j] > target) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = target;
    }

    finish = clock();

    duration = (double)(finish - start) / CLOCKS_PER_SEC;

    Print();
    cout << duration << "초" << "\n";
}

int main() {
    for (int i = 0; i < 2500; i++) {
        arr.push_back(rand() % 100);
    }

    Insertion_sort();
}