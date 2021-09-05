#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> adj;
vector<int> toNode;
vector<int> visitCount;
vector<int> nodeType;
vector<bool> visited;

void dfs(int node){
	++visitCount[node];
	for(int i=0; i<adj[node].size(); ++i){
		int next=adj[node][i];
		if(visitCount[next]>toNode[next]) continue;
		dfs(next);
	}
}

void checkReachable(int node){
	for(int i=0; i<adj[node].size(); ++i){
		int next=adj[node][i];
		if(visited[next]) continue;
		visitCount[next]=toNode[next]+1;
		checkReachable(next);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		
		adj=vector<vector<int>>(n+1, vector<int>());
		toNode=vector<int>(n+1,0);
		visitCount=vector<int>(n+1,0);
		
		for(int i=0; i<m; ++i){
			int a, b;
			cin>>a>>b;
			adj[a].push_back(b);
			toNode[b]++;
		}
		dfs(1);
		for(int i=2; i<=n; ++i) {
			if(visitCount[i]>toNode[i]) {
				visited=vector<bool>(n+1,false);
				checkReachable(i);
			}
		}
		for(int i=1; i<=n; ++i) {
			int ans;
			if(visitCount[i]==0)ans=0;
			else if(visitCount[i]==1)ans=1;
			else if(visitCount[i]>toNode[i])ans=-1;
			else ans=2;
			cout << ans <<' ';
		}
		cout<<'\n';
	}
}