#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

vector<vector<pair<int,int>>> adj;
vector<int> ans;
vector<int> length;
vector<int> nextNode;

void dfs(int u) {
	int& len=length[u]=0;
	int& nxt=nextNode[u];
	for(pair<int, int> p: adj[u]) {
		int v=p.first, w=p.second;
		if(v==1) {
			if(len < w) {
				len=w;
				nxt=1;
			}
			continue;
		}
		if(length[v]==-1) dfs(v);
		if(len<length[v]+w) {
			len=length[v]+w;
			nxt=v;
		}
	}
}

int main(void) {
	int n,m;
	cin >> n >> m;
	adj=vector<vector<pair<int,int>>> (n+1, vector<pair<int,int>>());
	length=vector<int> (n+1, -1);
	nextNode=vector<int> (n+1, -1);
	for(int i=0; i<m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}
	dfs(1);
	reverse(ans.begin(), ans.end());
	cout << length[1] << '\n';
	int u=1;
	while(true) {
		ans.push_back(u);
		if(nextNode[u]==1) break;
		u=nextNode[u];
	}
	ans.push_back(1);
	for(int a: ans) cout << a << ' ';
	cout << '\n';
}