#include<bits/stdc++.h>

using namespace std;

int arr[5] = {2, 5, 3, 1, 4};

void select_sort() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    select_sort();

    for(int a : arr) {
        cout << a << " ";
    }
}