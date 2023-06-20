#include<bits/stdc++.h>

using namespace std;

int arr[8] = {1, 10, 20, 40, 50, 60, 60, 70};
int LowerBound(int key) {
    int start = 0;
    int end = 8;
    int mid;
    
    while(start < end) {
        mid = (start + end) / 2;

        if(arr[mid] < key) //key값이 중앙 값보다 크면
            start = mid + 1;//현재 mid보다 오른쪽으로
        else 
            end = mid; //현재 mid 포함 왼쪽

        //cout << start << " " << mid << " " << end << "\n";
    }
    //cout << end << " ";
    return end;
}

int UpperBound(int key) {
    int start = 0;
    int end = 8;
    int mid;

    while(start < end) {
        mid = (start + end) / 2;

        if(arr[mid] <= key) //lowerBound와 요기만 다름
            start = mid + 1;
        else
            end = mid;
    }
    return end; //시작위치 == 끝 위치가 되면 빠져 나옴
}

int main() {
    cout << LowerBound(60) << "\n";
    cout << UpperBound(60) << "\n";
    
    cout << UpperBound(60) - LowerBound(60);
}