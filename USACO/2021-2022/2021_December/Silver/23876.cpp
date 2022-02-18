#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long ll;
const long long INF=1e15;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> reachable[2];
int N, M;

/*TEST*/
vector<int> T;
void dfsTEST(int u) {
	visited[u]=true;
	T.push_back(u);
	for(int v: adj[u])
		if(!visited[v]) dfsTEST(v);
}
/*END*/

void dfs(int u, int se) {
	if(N==938 && M==1000) {
		cout << "se:  " << se << ' ' << u << '\n';
	}
	visited[u]=true;
	reachable[se].push_back(u);
	for(int v: adj[u])
		if(!visited[v]) dfs(v, se);
}

long long sq(long long a) {
	return a*a;
}

void solve() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M;
	// cout << N << ' ' << M << '\n';
	adj=vector<vector<int>> (N+1, vector<int>());	
	int m=-1;
	for(int i=0; i<M; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		if(N==938 && M==1000) {
			m=max(m, max(u,v));
			if(u==936||v==936) cout << u << ' ' << v << '\n';
		}
	}
	if(N==938 && M==1000) cout << "m: " << m << '\n';
	reachable[0].clear();
	reachable[1].clear();
	visited=vector<bool>(N+1, false);
	dfs(1, 0);
	visited=vector<bool>(N+1, false);
	dfs(N, 1);
	sort(reachable[0].begin(), reachable[0].end());
	sort(reachable[1].begin(), reachable[1].end());
	if(N==938 && M==1000) {
		visited=vector<bool>(N+1, false);
		dfsTEST(936);
		sort(T.begin(), T.end());
		for(int t: T) cout << t << ' ';
		cout << '\n';
	}
	long long diff=INF;
	int a=1, b=N;
	for(int u: reachable[0]) {
		int l=0, r=reachable[1].size()-1;
		while(l<=r) {
			int mid=l+(r-l)/2;
			if(mid==reachable[1].size()-1 || abs(u-reachable[1][mid]) <= abs(u-reachable[1][mid+1])) {
				r=mid-1;
				if(diff > sq(u-reachable[1][mid])) {
					diff=sq(u-reachable[1][mid]);
					a=u;
					b=reachable[1][mid];
				}
			}
			else l=mid+1;
		}
	}	
	int mid=a+(b-a)/2;
	// cout << "Two are: " << a << ' ' << b << '\n';
	cout <<  sq(mid-a)+sq(b-mid) << '\n';
}

int main(void) {
	int t;
	cin >> t;
	while(t--) solve();
}