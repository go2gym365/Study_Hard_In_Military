#include<bits/stdc++.h>

using namespace std;

int arr[500];

int Binary_search(int left, int right, int target) {
    while(left <= right) {
        int mid = (left + right) / 2;
        
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int Cur_Binary_Search(int left, int right, int target) {
    if(left > right) return -1;

    int mid = (left + right) / 2;
    if(arr[mid] == target)
        return mid;
    else if(arr[mid] > target)
        return Cur_Binary_Search(left, mid - 1, target);
    else
        return Cur_Binary_Search(mid + 1, right, target)
}

int main() {
    for(int i = 0; i < 500; i++) {
        arr[i] = i;
    }
}