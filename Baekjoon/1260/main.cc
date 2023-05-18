#include<bits/stdc++.h>
using namespace std;

int vertex, edge, start_point;
bool visited_DFS[1001];
bool visited_BFS[1001];
vector<int> v[1001];

void DFS(int start_point)
{
	cout << start_point << " ";
	visited_DFS[start_point] = true;
	
	for(int node : v[start_point])
	{
		if(!visited_DFS[node])
		{
			DFS(node);
		}
	}
}

void BFS(int start_point)
{
	queue<int> q;
	q.push(start_point);
	visited_BFS[start_point] = true;
	
	while(!q.empty())
	{
		int cur_node = q.front();
		q.pop();
		cout << cur_node << " ";
		for(int node : v[cur_node])
		{
			if(!visited_BFS[node])
			{
				visited_BFS[node] = true;
				q.push(node);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> vertex >> edge >> start_point;
	
	for(int i = 1; i <= edge; i++)
	{
		int start, dest;
		cin >> start >> dest;
		v[start].push_back(dest);
		v[dest].push_back(start);
	}
	
	for(int i = 1; i <= vertex; i++)
	{
		sort(v[i].begin(), v[i].end());
	}
	
	DFS(start_point);
	cout << "\n";
	BFS(start_point);
	return 0;
}