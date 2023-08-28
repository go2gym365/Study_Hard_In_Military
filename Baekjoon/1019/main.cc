#include<bits/stdc++.h>

using namespace std;

long long numbers[10];

void calculate(int num, int increase)
{
	while (num)
	{
		numbers[num % 10] += increase;

		num /= 10;
	}
}

void func(int start, int end, int placeOfnum)
{
	while (start % 10 && start <= end)
	{
		calculate(start, placeOfnum);

		start++;
	}

	if (start > end)
	{
		return;
	}

	while (end % 10 != 9 && start <= end)
	{
		calculate(end, placeOfnum);

		end--;
	}

	long long cnt = (end / 10 - start / 10 + 1);

	for (int i = 0; i < 10; i++)
	{
		numbers[i] += cnt * placeOfnum;
	}

	func(start / 10, end / 10, placeOfnum * 10);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	
	func(1, n, 1);

	for (int i = 0; i < 10; i++)
	{
		cout << numbers[i] << " ";
	}
}