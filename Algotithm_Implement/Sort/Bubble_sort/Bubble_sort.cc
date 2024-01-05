#include <bits/stdc++.h>

using namespace std;

int n;
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
    //Print();
    cout << "Bubble sort로 " << n << "개 원소 정렬에 걸린 시간 " << duration << "초" << "\n";
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        arr.push_back(rand() % 100);
    }

    bubbleSort();
}