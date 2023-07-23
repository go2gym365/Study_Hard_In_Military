#include<bits/stdc++.h>

using namespace std;

long long check[10] = {0, };

void calc(long long n, long long ten)
{
	while (n > 0) {
		check[n % 10] += ten;
		n /= 10;
	}
	return
}



void solve(long long A, long long B, long long ten) {
	// A를 ++ 시키면서 0을 만든다.
	while (A % 10 != 0 && A <= B)
	{
		// A를 ++ 시킬때는 calc를 거쳐야한다.
		calc(A, ten);
		A++;
	}

	if (A > B) return;

	while (B % 10 != 9 && B >= A)

	{

		//B를 -- 시킬때는 calc를 거쳐야 한다.

		calc(B, ten);

		B--;

	}



	long long cnt = (B / 10 - A / 10 + 1);

	//B-A +1 * 자리수 만큼 0~9에 각각 더해준다.

	for (int i = 0; i < 10; ++i)

		check[i] += cnt * ten;



	// 다음자리 수를 계산위해 재귀함수 호출한다.

	solve(A / 10, B / 10, ten * 10);

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    calc(n);

    for(int i = 0; i < 10; i++) {
        cout << check[i] << " ";
    }
}