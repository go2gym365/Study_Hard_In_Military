#include<bits/stdc++.h>

using namespace std;

int main() {
    int cnt = 0;

    string nowDate;
    cin >> nowDate;

    int year = (nowDate[0] - '0') * 1000 + (nowDate[1] - '0') * 100 + (nowDate[2] - '0') * 10 + (nowDate[3] - '0') ;
    int month = (nowDate[5] - '0') * 10 + (nowDate[6] - '0');
    int day = (nowDate[8] - '0') * 10 + (nowDate[9] - '0');

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string date;
        cin >> date;

        int dyear = (nowDate[0] - '0') * 1000 + (nowDate[1] - '0') * 100 + (nowDate[2] - '0') * 10 + (nowDate[3] - '0') ;
        int dmonth = (nowDate[5] - '0') * 10 + (nowDate[6] - '0');
        int dday = (nowDate[8] - '0') * 10 + (nowDate[9] - '0');

        if(year >= dyear && month >= dmonth && day >= dday) cnt++;
    }
    cout << cnt;
}