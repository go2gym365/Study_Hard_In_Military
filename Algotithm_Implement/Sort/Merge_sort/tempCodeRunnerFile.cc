#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
int* sorted;

void Print() {
    for (int i = 0; i < arr.size(); i++) {
        cout << sorted[i] << ' ';
    }
    cout << "\n";
}

void merge(int left, int mid, int right) {
    int leftIdx = left;
    int rightIdx = mid+1;
    int sortIdx = left;

    while(leftIdx <= mid && rightIdx <= right) {
        if(arr[leftIdx] <= arr[rightIdx]) {
            sorted[sortIdx] = arr[leftIdx];
            leftIdx++;
        }
        else {
            sorted[sortIdx] = arr[rightIdx];
            rightIdx++;
        }
        sortIdx++;
    }

    if(leftIdx > mid) {
        for(int i = rightIdx; i <= right; i++) {
            sorted[sortIdx] = arr[i];
            sortIdx++;
        }
    }
    else {
        for(int i = leftIdx; i <= mid; i++) {
            sorted[sortIdx] = arr[i];
            sortIdx++;
        }
    }

    for(int i = left; i <= right; i++) {
        arr[i] = sorted[i];
    }
} 

void division(int left, int right) {
    int mid;

    if(left < right) {
        mid = (left + right) / 2;

        division(left, mid);
        division(mid+1, right);
        merge(left, mid, right);
    }
}

void mergeSort() {
    division(0, arr.size()-1);
}


int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        arr.push_back(rand() % 100);
    }

    sorted = new int[n];

    clock_t start, finish;
    double duration;
    start = clock();

    mergeSort();

    finish = clock();
    //Print();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << duration << "초" << "\n";
}