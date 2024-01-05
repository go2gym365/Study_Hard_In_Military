#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
int sorted[2500];

void Print() {
    for (int i = 0; i < arr.size(); i++) {
        cout << sorted[i] << ' ';
    }
    cout << "\n";
}

void merge(int left, int mid, int right) {
    int leftStart = left;
    int rightStart = mid+1;
    int sortedIdx = left;

    while (leftStart <= mid && rightStart <= right) {
        if(arr[leftStart] <= arr[rightStart]) {
            sorted[sortedIdx] = arr[leftStart];
            leftStart++;
        }
        else {
            sorted[sortedIdx] = arr[rightStart];
            rightStart++;
        }
        sortedIdx++;
    }

    //왼쪽 애들은 이미 정렬 됨 > 오른쪽 애들만 정렬해주면 됨.
    if(leftStart > mid) {
        for(int t = rightStart; t <= right; t++) {
            sorted[sortedIdx] = arr[t];
            sortedIdx++;
        }
    }
    //오른쪽 애들은 이미 정리 됨. > 왼쪽 애들만 정렬해주면 됨.
    else {
        for(int t = leftStart; t <= mid; t++) {
            sorted[sortedIdx] = arr[t];
            sortedIdx++;
        }
    }

    for(int i = left; i <= right; i++) {
        arr[i] = sorted[i];
    }
}

void partition(int left, int right) {
    int mid;

    if (left < right) {
        mid = (left + right) / 2;

        partition(left, mid);
        partition(mid + 1, right);
        merge(left, mid, right);
    }

    return;
}

int main() {
    // int n;
    // cin >> n;

    for (int i = 0; i < 2500; i++) {
        // int a;
        // cin >> a;
        arr.push_back(rand() % 100);
    }

    clock_t start, finish;
    double duration;
    start = clock();

    partition(0, arr.size() - 1);

    finish = clock();
    Print();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << duration << "초" << "\n";
}