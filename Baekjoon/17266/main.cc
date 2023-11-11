#include <iostream>
#include <vector>

using namespace std;

int n, m;

vector<int> input;

int binarySearch() {
    int start = 0;
    int end = n;
    int mid;
    
    while(start + 1 < end) {
        bool check = false;
        mid = (start + end) / 2;
        if(input[0] > mid) check = true;
        for(int i = 0; i < m-1; i++) {
            if(input[i+1]-input[i] > mid * 2) {
                check = true;
                break;
            }
        }
        if(n-input[m-1] > mid) check = true;
        
        if(check) start = mid;
        else end = mid;
    }
    return end;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int light;
        cin >> light;
        
        input.push_back(light);
    }
    
    cout << binarySearch();
}
