#include<iostream>
#include<utility>
#include<vector>
#include<cstring>

using namespace std;

vector<pair<int,int>> adj[10001];
bool visited[10001];

// dfs from node
// if ret is updated, return the leaf node and length
// else return the leaf
pair<int, int> dfs(int node) {
	visited[node] = true;
	pair<int, int> ret = {node, 0};
	for(int i = 0; i < adj[node].size(); ++i) {
		int next = adj[node][i].first;
		int len = adj[node][i].second;
		if(visited[next]) continue;
		pair<int,int> nextRet = dfs(next);
		int end = nextRet.first;
		int nextLen = nextRet.second;
		if(ret.second < nextLen + len) ret = make_pair(end, nextLen + len);
	}
	return ret;
}

int main(void) {
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	
	for(int i = 0; i+1 < n; ++i) {
		int a, b, len;
		cin >> a >> b >> len;
		adj[a].push_back(make_pair(b, len));
		adj[b].push_back(make_pair(a, len));
	}
	
	pair<int,int> ret = dfs(1);
	int end = ret.first;
	memset(visited, 0, sizeof(visited));
	pair<int, int> ans = dfs(end);
	cout << ans.second << '\n';
}