#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
string ques;
ll GCD(ll x, ll y) {
    if (y == 0)
        return x;
    return GCD(y, x % y);
}
// 비순환 소수는 순환소수 앞에만 나올 수 있다.
void makeans(string A) {
    int SS = A.size();
    // 분자
    ll BoonJa = 0LL;
    // 앞에 두개는 '0.' 이므로 3번째부터 봄
    int idx = 2;
    while (1) {
        if (idx == SS)
            break;
        if (A[idx] == '(')
            break;
        BoonJa = BoonJa * 10 + (A[idx] - '0');
        idx++;
    }
    // 비순환 소수 자리수
    int cnt = idx - 2;
    // 순환 소수 자리수
    int cnt2 = 0;
    // 순환소수 있을때 A[idx] = '(' 상태
    if (idx != SS) {
        // temp2 = 비순환 소수
        ll temp2 = BoonJa;
        while (1) {
            idx++;
            if (A[idx] == ')')
                break;
            BoonJa = BoonJa * 10 + (A[idx] - '0');
            cnt2++;
        }
        // 전체 - 비순환소수
        if (BoonJa != temp2)
            BoonJa -= temp2;
    }
    // 분모
    ll BoonMo = 0LL;
    // 순환소수 자리 수만큼 분모에 9채우기
    while (cnt2--)
        BoonMo = BoonMo * 10 + 9;
    if (BoonMo == 0LL)
        BoonMo = 1LL;
    // 비순환 소수 자리 수만큼 분모 뒤에 0 채우기
    while (cnt--)
        BoonMo *= 10;
    ll G = GCD(BoonMo, BoonJa);
    cout << "YES\n";
    cout << BoonJa / G << ' ' << BoonMo / G << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> ques;
        makeans(ques);
    }

    return 0;
}