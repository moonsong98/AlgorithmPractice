#include<bits/stdc++.h>
using namespace std;

int sqr(int a) {
	return a*a;
}

struct cow{
	int y, x, p;
	bool inBound(const cow& c) {
		return sqr(c.x-x)+sqr(c.y-y)<=sqr(p);
	}
};

int main(void) {
	int N; cin >> N;
	vector<cow> cows(N);
	vector<vector<int>> adj(N);
	for(int i=0; i<N; ++i) {
		int x, y, p;
		cin >> cows[i].x >> cows[i].y >> cows[i].p;
	}
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j)
		if(i!=j && cows[i].inBound(cows[j])) adj[i].push_back(j);
	int ans=-1;
	for(int i=0; i<N; ++i) {
		vector<bool> found(N, false);
		int cnt=1;
		found[i]=true;
		queue<int> q;
		q.push(i);
		while(!q.empty()) {
			int u=q.front(); q.pop();
			for(int v: adj[u])
				if(!found[v]) {
					cnt++;
					found[v]=true;
					q.push(v);
				}
		}
		ans=max(ans, cnt);
	}
	cout << ans << '\n';
}
