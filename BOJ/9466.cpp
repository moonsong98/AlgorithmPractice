#include<iostream>
#include<vector>

using namespace std;

vector<int> p;
vector<bool> visited, finished, hasTeam;

void checkTeam(int u, int leader) {
	hasTeam[u]=true;
	if(!(p[u]==leader)) checkTeam(p[u], leader);
}

void findCycle(int u) {
	visited[u]=true;
	if(!visited[p[u]]) findCycle(p[u]);
	else if(!finished[p[u]]) checkTeam(p[u], p[u]);
	finished[u]=true;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;	
		p=vector<int>(n+1, 0); for(int i=1; i<=n; ++i) cin >> p[i];
		visited=vector<bool>(n+1, false);
		finished=vector<bool>(n+1, false);
		hasTeam=vector<bool>(n+1, false);
		for(int i=1; i<=n; ++i) if(!finished[i]) findCycle(i);
		int ans=-1;
		for(bool h: hasTeam)
			if(!h) ++ans;
		cout << ans << '\n';
	}
}