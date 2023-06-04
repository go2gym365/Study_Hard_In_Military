#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;

bool Compare(pair<int, int> A, pair<int, int> B)
{
    if (A.first == B.first)
        return A.second < B.second;
    return A.first < B.first;
}

int main()
{
    int n;
    int cnt = 0;
    int temp = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        v.push_back({start, end});
    }

    sort(v.begin(), v.end(), Compare);

    for (int i = 0; i < n; i++)
    {
        if (temp < v[i].second && temp >= v[i].first)
        {
            cnt = cnt + (v[i].second - temp);
        }
        else if (temp < v[i].first)
        {
            cnt += v[i].second - v[i].first;
        }
        temp = v[i].second;
    }

    cout << cnt;
}