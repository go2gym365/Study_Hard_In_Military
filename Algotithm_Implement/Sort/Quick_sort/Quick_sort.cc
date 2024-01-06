#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

void Print() {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ' ';
    }
    cout << "\n";
}

int division(int left, int right) {
    int mid = (left + right) / 2;
    swap(arr[left], arr[mid]);

    int pivot = arr[left];
    int i = left;
    int j = right;

    while(i < j) {
        //우측에서 pivot보다 작은애를 찾을 때 까지 움직임
        while(pivot < arr[j]) {
            j--;
        }
        //좌측에서 pivot보다 큰애 찾을 때 까지
        while(i < j && pivot >= arr[i]) {
            i++;
        }
        swap(arr[i], arr[j]);
    }

    arr[left] = arr[i];
    arr[i] = pivot;
    //swap(arr[left], arr[i]);
    
    return i;
}

void quickSort(int left, int right) {
    if(left >= right) return;

    int pivot = division(left, right);

    quickSort(left, pivot-1);
    quickSort(pivot+1, right);
}


int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        arr.push_back(rand());
    }

    clock_t start, finish;
    double duration;
    start = clock();

    quickSort(0, arr.size()-1);

    finish = clock();
    //Print();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "Quick sort로 " << n << "개 원소 정렬에 걸린 시간 " << duration << "초" << "\n";
}