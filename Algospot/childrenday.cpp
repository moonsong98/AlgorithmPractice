#include<bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while(t--) {
		string d;
		int n, m;
		cin >> d >> n >> m;
		sort(d.begin(), d.end());
		vector<int> parent(2*n,-1), choice(2*n,-1);
		parent[0]=0;
		queue<int> q;
		auto next=[=](int u, int x, int n)->int{
			int v=u*10+x;
			if(v>=n) return n+v%n;
			return v%n;
		};
		q.push(0);
		while(!q.empty()) {
			int u=q.front();
			q.pop();
			for(char x: d) {
				int v=next(u,x-'0',n);
				if(parent[v]==-1) {
					parent[v]=u;
					choice[v]=x-'0';
					q.push(v);
				}
			}
		}
		if(parent[n+m]==-1) cout << "IMPOSSIBLE\n";
		else {
			int u=n+m;
			string str;
			while(u!=parent[u]) {
				str+=char('0'+choice[u]);
				u=parent[u];
			}
			reverse(str.begin(), str.end());
			cout << str << '\n';
		}
	}
}