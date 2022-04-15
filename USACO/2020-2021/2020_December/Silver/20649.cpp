#include<bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;

struct El {
	char dir;
	int y, x;
};

struct Log {
	int time, u, v;
	int hasToMove;
};

bool operator < (const Log& a, const Log& b) {
	return a.time < b.time;
}

vector<El> el;
vector<vector<int>> adj;
vector<Log> logs;
vector<int> parent, moveLen;
vector<int> ans;

void dfs(int u) {
	ans[u]=0;
	for(int v: adj[u]) {
		if(ans[v]==-1)
			dfs(v);
		ans[u]+=ans[v]+1;
	}
}

int main(void) {
	int N; cin >> N;
	adj=vector<vector<int>> (N);
	el=vector<El>(N);
	parent=vector<int>(N);
	moveLen=vector<int>(N, -1);
	ans=vector<int>(N,-1);
	for(int i=0; i<N; ++i) parent[i]=i;
	for(int i=0; i<N; ++i)
		cin >> el[i].dir >> el[i].x >> el[i].y;
	for(int i=0; i<N; ++i) for(int j=i+1; j<N; ++j) {
		if(el[i].x-el[j].x==el[j].y-el[i].y) continue;
		int time, u=-1, v, hasToMove;
		if(el[i].x<=el[j].x && el[i].y>=el[j].y && el[i].dir=='E'&&el[j].dir=='N')
			if(el[j].x-el[i].x>el[i].y-el[j].y)
				time=el[j].x-el[i].x, u=i, v=j, hasToMove=el[i].y-el[j].y;
			else
				time=el[i].y-el[j].y, u=j, v=i, hasToMove=el[j].x-el[i].x;
		else if(el[i].x>=el[j].x && el[i].y<=el[j].y && el[i].dir=='N' && el[j].dir=='E')
			if(el[i].x-el[j].x>el[j].y-el[i].y)
				time=el[i].x-el[j].x, u=j, v=i, hasToMove=el[j].y-el[i].y;
			else
				time=el[j].y-el[i].y, u=i, v=j, hasToMove=el[i].x-el[j].x;
		else if(el[i].dir==el[j].dir) {
			if(el[i].dir=='N' && el[i].x==el[j].x) {
				if(el[i].y>el[j].y) 
					time=el[i].y-el[j].y, u=j, v=i, hasToMove=0;
				else
					time=el[j].y-el[i].y, u=i, v=j, hasToMove=0;
			}
			else if(el[i].dir=='E' && el[i].y==el[j].y) {
				if(el[i].x>el[j].x) 
					time=el[i].x-el[j].x, u=j, v=i, hasToMove=0;
				else
					time=el[j].x-el[i].x, u=i, v=j, hasToMove=0;
			}
		}
		if(u==-1) continue;
		Log l; l.time=time, l.u=u, l.v=v, l.hasToMove=hasToMove;
		logs.push_back(l);
	}
	sort(all(logs));
	for(auto l: logs) {
		if(parent[l.u]!=l.u) continue;
		if(parent[l.v]!=l.v&&moveLen[l.v]<l.hasToMove) continue;
		parent[l.u]=l.v;
		adj[l.v].push_back(l.u);
		moveLen[l.u]=l.time;
	}
	for(int i=0; i<N; ++i)
		if(ans[i]==-1)
			dfs(i);
	for(int i=0; i<N; ++i)
		cout << ans[i] << '\n';
}