#include<bits/stdc++.h>

using namespace std;

int n, m;
int arr[500001];

int LowerBound(int key) {
    int start = 0;
    int end = n;
    int mid;
    
    while(start < end) {
        mid = (start + end) / 2;

        if(arr[mid] < key) //key값이 중앙 값보다 크면
            start = mid + 1;//현재 mid보다 오른쪽으로
        else 
            end = mid; //현재 mid 포함 왼쪽
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
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
        cout << upper_bound(arr, arr + n, b) - lower_bound(arr, arr + n, b) << " ";
    }
}