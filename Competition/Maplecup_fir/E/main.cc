#include<bits/stdc++.h>

using namespace std;

int goldCard[5];
vector<int> vec;
const int INF = -987654321;

int main() {
    int goldCardCnt = 0;
    int stageCnt = 0;

    int n, startGold, salary, goldNum;
    cin >> n >> startGold >> salary >> goldNum;

    for(int i = 1; i <= 4; i++) {
        int a, detail;
        cin >> a >> detail;

        goldCard[a] = detail;
    }

    vec.push_back(INF);

    for(int i = 1; i < 4 * n - 4; i++) {
        char ch;
        int num;
        cin >> num;
        if(num / n == 0) {
            vec.push_back(INF);
            continue;
        }
        if(ch == 'G') vec.push_back(-1);
        else if(ch == 'L') vec.push_back(num);
    }


    for(int a : vec) {
        cout << a << " ";
    }
    return 0;
    int cul;
    cin >> cul;

    for(int i = 0; i < n; i++) {
        int f, s;
        int sum;
        cin >> f >> s;
        sum = f + s;

        //calc
        goldCardCnt += sum;

        //if(vec[goldCardCnt % (4*n - 4)])
    }
}