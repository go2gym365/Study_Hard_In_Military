#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> input;
vector<int> sum;

bool binarySearch(int tar) {
    int start = 0;
    int end = sum.size() - 1;

    while(start < end) {
        int mid = (start + end) / 2;

        if(sum[mid] == tar) {
            return true;
        }

        if(sum[mid] < tar) {
            start = mid + 1;
        }
        else {
            end = mid;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        input.push_back(a);
    }

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            sum.push_back(input[i] + input[j]);
        }
    }

    sort(input.begin(), input.end());
    sort(sum.begin(), sum.end());

    for(int i = n-1; i >= 0; i--) {
        for(int j = i; j >= 0; j--) {
            int a = input[i] - input[j];

            //bool check = binary_search(sum.begin(), sum.end(), a);
            bool check = binarySearch(a);
            if (check) {
                cout << input[i];
                return 0;
            }
        }
    }
}