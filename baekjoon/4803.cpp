#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> adj;
vector<int> visited;

bool dfs(int u, int p) {
	bool ret = true;
	visited[u]=true;
	for(int v: adj[u]) {
		if(v==p) continue;
		if(visited[v]!=-1) ret=false;
		else ret=ret&&dfs(v,u);
	}
	return ret;
}

int main(void) {
	int caseNum=0;
	while(true) {
		caseNum++;
		int ans=0;
		int a, b;
		cin >> a >> b;
		if(!a&&!b) break;
		adj=vector<vector<int>> (a+1, vector<int>());
		visited=vector<int>(a+1, -1);
		for(int i=0; i<b; ++i) {
			int u, v;
			cin >> u>> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		for(int i=1; i<=a; ++i)
			if(visited[i]==-1 && dfs(i, -1)) {
				ans++;	
			}
		cout << "Case " << caseNum << ": ";
		if(ans>1) cout << "A forest of " << ans << " trees." << '\n';
		else if(ans==1) cout << "There is one tree." << '\n';
		else cout << "No trees." << '\n';
	}
}