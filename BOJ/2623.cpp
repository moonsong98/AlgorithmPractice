#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> finished, found, ans;
int counter;

void dfs(int u) {
	found[u]=++counter;
	for(int v: adj[u]) {
		if(found[v]==-1) dfs(v);
		else {
			if(finished[v]==0) {
				cout << 0 << '\n';
				exit(0);
			}
		}
	}
	ans.push_back(u);
	finished[u]=true;
}

int main(void) {
	int n, m;
	cin >> n >> m;
	adj=vector<vector<int>> (n+1, vector<int>());
	finished=vector<int>(n+1, 0);
	found=vector<int>(n+1,-1);
	for(int i=0; i<m; ++i) {
		int a, b, c=-1;
		cin >> a >> b;
		for(int j=0; j+1<a; ++j){ 
			cin >> c;
			adj[b].push_back(c);
			b=c;
		}
	}
	for(int i=1; i<=n; ++i) 
		if(found[i]==-1) dfs(i);
			
	reverse(ans.begin(), ans.end());
	for(int a:ans) cout << a << '\n';
}