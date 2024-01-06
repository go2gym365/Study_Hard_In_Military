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
        //오른쪽부터 pivot보다 작은애들 찾기
        //작은애들을 먼저 찾아야 pivot과 swap할 때 중간값을 기준으로 정렬이 됨.
        while(pivot < arr[j]) {
            j--;
        }
        //왼쪽부터 pivot보다 큰 애들 찾기
        //i < j를 넣어줌으로써 한 인덱스로 수렴이 됨.
        //i == j면 루프를 안들어오기 때문에 값은 결국 pivot보다 작은 값으로 수렴됨.
        while(i < j && pivot >= arr[i]) {
            i++;
        }

        swap(arr[i], arr[j]);
    }

    //현재 i를 기준으로 왼쪽에는 pivot보다 작은 값들이, 
    //오른쪽에는 pivot보다 큰 값들이 순서상관없이 정렬되어 있다.
    //처음에 바꿔준 pivot과 pivot보다 작은 값을 swap하면
    //배열상에서도 i를 기준으로 좌측은 i보다 작은값 우측은 i보다 큰 값만 존재
    swap(arr[left], arr[i]);

    //i를 기준으로 좌, 우는 값만 작다 크다로 나눠져있지 순서는 보장되지 않기 때문에
    // 분할을 통해 다시 좌, 우의 순서를 맞추기위해 i를 기준으로 나눠서 재귀를 호출해야 한다
    return i;
}

void quickSort(int left, int right) {
    //기저조건 : 하나의 원소로 수렴하면 return
    if(left >= right) return;

    //기준점을 받아와서
    int pivot = division(left, right);

    //이 pivot을 기준으로 좌, 우 분할 정복때리기
    quickSort(left, pivot-1);
    quickSort(pivot+1, right);
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        arr.push_back(rand() % 100);
    }

    clock_t start, finish;
    double duration;
    start = clock();

    quickSort(0, arr.size()-1);

    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    Print();
    cout << "Quick sort로 " << n << "개 원소 정렬에 걸린 시간 " << duration << "초" << "\n";
}