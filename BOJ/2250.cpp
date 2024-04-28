#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj, lr;
vector<int> depth, sz, sp, pos;
int height=-1;

int traversal(int u, int d) {
	height=max(height, d);
	sz[u]=1;
	depth[u]=d;
	for(int i=0; i<2; ++i)
		if(adj[u][i]!=-1)
			sz[u]+=traversal(adj[u][i], d+1);
	return sz[u];
}

void calcPos(int u, int sp) {
	int leftsz=0;
	if(adj[u][0]!=-1) leftsz=sz[adj[u][0]];
	pos[u]=sp+leftsz;
	if(adj[u][0]!=-1)
		calcPos(adj[u][0],sp);
	if(adj[u][1]!=-1)
		calcPos(adj[u][1],sp+leftsz+1);
}
	
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	vector<bool> appear(n+1, false);
	adj=vector<vector<int>>(n+1, vector<int>(2));
	depth=vector<int>(n+1);
	sz=vector<int>(n+1);
	pos=vector<int>(n+1);
	for(int i=0; i<n; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		if(b!=-1) appear[b]=true;
		if(c!=-1) appear[c]=true;
		adj[a][0]=b, adj[a][1]=c;
	}
	int root;
	for(int i=1; i<=n; ++i)
		if(!appear[i]){
			root=i;
			break;
		}
	traversal(root, 1);
	calcPos(root, 1);
	lr=vector<vector<int>>(height+1, vector<int>(2, -1));
	for(int i=1; i<=n; ++i) {
		if(lr[depth[i]][0]==-1) lr[depth[i]][0]=lr[depth[i]][1]=pos[i];
		else {
			lr[depth[i]][0]=min(lr[depth[i]][0], pos[i]);
			lr[depth[i]][1]=max(lr[depth[i]][1], pos[i]);
		}
	}
	int ans[2]={1, 1};
	for(int i=1; i<=height; ++i) {
		if(lr[i][1]-lr[i][0]+1>ans[1]) {
			ans[0]=i;
			ans[1]=lr[i][1]-lr[i][0]+1;
		}
	}
	cout << ans[0] << ' ' << ans[1] << '\n';
}