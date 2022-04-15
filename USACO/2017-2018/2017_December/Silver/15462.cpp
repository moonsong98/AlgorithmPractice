#include<bits/stdc++.h>
using namespace std;

vector<int> nxt;
vector<bool> visited, finished;
int ans=0;

void dfs(int u) {
	visited[u]=true;
	int v=nxt[u];
	if(!visited[v]) dfs(v);
	if(!finished[v]) {
		for(int i=v; i!=u; i=nxt[i]) ++ans;
		++ans;
	}
	finished[u]=true;
}

int main(void) {
	int N; cin >> N;
	nxt=vector<int>(N+1);
	visited=vector<bool>(N+1, false);
	finished=vector<bool>(N+1, false);
	for(int i=1; i<=N; ++i) cin >> nxt[i];
	for(int i=1; i<=N; ++i)
		if(!visited[i]) dfs(i);
	cout << ans << '\n';
}