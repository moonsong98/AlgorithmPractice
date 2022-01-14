#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct{
	int u, v, cost;
} edge;

bool operator < (edge u, edge v){
	return u.cost < v.cost;
}

vector<int> parent;
vector<int> r;

int find(int u) {
	if(u==parent[u]) return u;
	return parent[u]=find(parent[u]);
}

void merge(int u, int v) {
	u=find(u); v=find(v);
	if(u==v) return;
	if(r[u]<r[v]) parent[u]=v;
	else parent[v]=u;
	if(r[u]==r[v]) r[v]++;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m, ans=0; cin >> n >> m;
	for(int i=0; i<=n; ++i) {
		parent.push_back(i);
		r.push_back(0);
	}
    vector<edge> edgeList;
	for(int i=0; i<m; ++i) {
		int a, b, c; cin >> a >> b >> c;
		edgeList.push_back({a, b, c});
	}
	sort(edgeList.begin(), edgeList.end());
	for(edge e: edgeList) {
		int u=e.u, v=e.v, cost=e.cost;
		if(find(u)!=find(v)) {
			ans+=cost;
			merge(u, v);
		}
	}
	cout << ans << '\n';
}
