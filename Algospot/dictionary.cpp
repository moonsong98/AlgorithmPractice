#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;

vector<vector<bool>> adj;
vector<bool> visited, finished;
vector<int> ans;

bool dfs(int u) {
	visited[u]=true;
	bool ret=true;
	for(int v=0; v<26; ++v) {
		if(adj[u][v])
			if(!visited[v])
				ret=ret&&dfs(v);
			else if(!finished[v])
				ret=false;
	}
	ans.push_back(u);
	finished[u]=true;
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		string a, b;
		cin >> a;
		adj=vector<vector<bool>> (26, vector<bool>(26, false));
		visited=vector<bool>(26, false);
		finished=vector<bool>(26, false);
		ans.clear();
		for(int i=0; i+1<n; ++i) {
			cin >> b;
			int len=min(sz(a),sz(b));
			for(int j=0; j<len; ++j) {
				if(a[j]!=b[j]) {
					adj[a[j]-'a'][b[j]-'a']=true;
					break;
				}
			}
			a=b;
		}
		bool res=true;
		for(int i=0; i<26; ++i) {
			if(visited[i]==false) {
				res=dfs(i);
				if(res==false) {
					cout << "INVALID HYPOTHESIS" << '\n';
					break;
				}
			}
		}
		if(res==false) continue;
		reverse(ans.begin(), ans.end());
		for(int n: ans) cout << char('a'+n);
		cout << '\n';
	}
}