#include<iostream>
#include<utility>
#include<vector>
#include<cstring>

using namespace std;

vector<pair<int,int>> adj[100001];
bool visited[100001];

pair<int, int> dfs(int node) {
	visited[node] = true;	
	pair<int, int> ret = make_pair(node, 0);
	for(int i = 0; i < adj[node].size(); ++i) {
		int next = adj[node][i].first;
		int len = adj[node][i].second;
		if(visited[next]) continue;
		pair<int,int> nextResult = dfs(next);
		if(ret.second < nextResult.second + len)
			ret = make_pair(nextResult.first, nextResult.second + len);
	}
	return ret;
}

int main(void) {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int node, adjNode, len;
		cin >> node;
		cin >> adjNode;
		while(adjNode != -1) {
			cin >> len;
			adj[node].push_back(make_pair(adjNode, len));
			cin >> adjNode;
		}
	}
	
	pair<int, int> ret = dfs(1);
	int end = ret.first;
	memset(visited, 0, sizeof(visited));
	pair<int, int> ans = dfs(end);
	cout << ans.second << endl;
}