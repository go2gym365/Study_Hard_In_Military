#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

void Print() {
    for (int a : arr) {
        cout << a << " ";
    }
    cout << "\n";
}

void bubbleSort() {
    clock_t start, finish;
    double duration;

    start = clock();

    for (int i = 0; i < arr.size() - 1; i++) {
        bool isSwap = false;
        // 뒤에서 i개는 정렬이 무조건 되기 때문에 i씩 빼주기
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if (!isSwap)
            break;
    }

    finish = clock();

    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    Print();
    cout << duration << "초" << "\n";
}

int main() {
    // int n;
    // cin >> n;

    for (int i = 0; i < 2500; i++) {
        // int a;
        // cin >> a;
        arr.push_back(rand() % 100);
    }

    bubbleSort();
}