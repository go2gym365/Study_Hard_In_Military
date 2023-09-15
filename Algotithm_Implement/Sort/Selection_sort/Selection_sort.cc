#include<bits/stdc++.h>

using namespace std;

vector<int> arr;

void selectionSort() {
    //마지막 값은 자동 정렬이 되었기 때문에 n-1
    for(int i = 0; i < arr.size() - 1; i++) {
        //최솟값을 가진 인덱스를 저장
        int minIdx = i;
        //최솟값을 저장하여 바꾸기때문에 매번 i까지는 정렬이 됨
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[minIdx] > arr[j]) {
                minIdx = j;
            }
        }
        //최솟값을 가진곳을 확인 했기 때문에 바꿔줌
        swap(arr[minIdx], arr[i]);
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

    selectionSort();

    for(int a : arr) {
        cout << a << " ";
    }
}