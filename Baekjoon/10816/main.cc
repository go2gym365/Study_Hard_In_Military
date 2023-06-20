#include<bits/stdc++.h>

using namespace std;

int n, m;
int arr[500001];

int lowBinarySearch(int num) {
    int start = 0;
    int end = n;

    while(start < end) {
        int mid = (start + end) / 2;

        if(num <= arr[mid]) {
            
        }
    }
}

int highBinarySearch(int num) {
    int start = 0;
    int end = n;
    int mid = (start + end) / 2;

    while()
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr[i] = a;
    }

    sort(arr, arr + n);

    cin >> m;
    for(int i = 0; i < m; i++) {
        int b;
        cin >> b;
        cout << highBinarySearch(b) - lowBinarySearch(b);
    }
}