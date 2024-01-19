#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n, m;
	char data[50][50];
	int x[50], y[50];
 
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			cin >> data[i][j];
			if (data[i][j] == 'X')
			{
				x[j] = 1;	//그 열이나 행에 있어도 1로 표시하여 없는 행을 구한다.
				y[i] = 1;
			}
		}
	}
 
	int xCount = 0;
	for (int j = 0; j < m; j++)
	{
		if (x[j] == 0) xCount++;	//없는 행의 수
	}
 
	int yCount = 0;
	for (int i = 0; i < n; i++)
	{
		if (y[i] == 0) yCount++;
	}
 
	cout << max(xCount, yCount);	//더 많이 없는 곳에 배치
}