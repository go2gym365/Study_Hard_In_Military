#include <bits/stdc++.h>

using namespace std;

int n;

int arr[3];
int maxVal[3];
int minVal[3];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;

    cin >> arr[0] >> arr[1] >> arr[2];

    //초기화
    for (int i = 0; i < 3; i++) {
        maxVal[i] = minVal[i] = arr[i];
    }

    for (int i = 1; i < n; i++) {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;

        int tempMax0 = maxVal[0];
        int tempMax1 = maxVal[1];
        int tempMax2 = maxVal[2];

        maxVal[0] = max(tempMax0, tempMax1) + n1;
        maxVal[1] = max(max(tempMax0, tempMax1), tempMax2) + n2;
        maxVal[2] = max(tempMax1, tempMax2) + n3;

        int tempMin0 = minVal[0];
        int tempMin1 = minVal[1];
        int tempMin2 = minVal[2];

        minVal[0] = min(tempMin0, tempMin1) + n1;
        minVal[1] = min(min(tempMin0, tempMin1), tempMin2) + n2;
        minVal[2] = min(tempMin1, tempMin2) + n3;
    }

    cout << max(max(maxVal[0], maxVal[1]), maxVal[2]) << ' ';
    cout << min(min(minVal[0], minVal[1]), minVal[2]);
}