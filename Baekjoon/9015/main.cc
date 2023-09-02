#include<bits/stdc++.h>

using namespace std;

bool vis[10000];

void BFS(int a, int b)
{
    queue<pair<int, string>> q;
    q.push(make_pair(a, ""));
    vis[a] = true;

    while (!q.empty())
    {
        int cur_num = q.front().first;
        string cur_op = q.front().second;
        q.pop();

        if (cur_num == b)
        {
            cout << cur_op << '\n';
            return;
        }

        int D, S, L, R, temp;
        // D 연산
        D = (cur_num * 2) % 10000;
        if (!vis[D])
        {
            vis[D] = true;
            q.push(make_pair(D, cur_op + "D"));
        }

        // S 연산
        S = cur_num - 1 < 0 ? 9999 : cur_num - 1;
        if (!vis[S])
        {
            vis[S] = true;
            q.push(make_pair(S, cur_op + "S"));
        }

        // L 연산
        L = (cur_num % 1000) * 10 + (cur_num / 1000);
        if (!vis[L])
        {
            vis[L] = true;
            q.push(make_pair(L, cur_op + "L"));
        }

        // R 연산
        R = cur_num / 10 + (cur_num % 10) * 1000;
        if (!vis[R])
        {
            vis[R] = true;
            q.push(make_pair(R, cur_op + "R"));
        }
    }
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int start, end;
        cin >> start >> end;

        memset(vis, false, sizeof(vis));

        BFS(start, end);
    }
}