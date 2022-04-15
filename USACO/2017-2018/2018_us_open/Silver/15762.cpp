#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

vector<vector<int>> b, compID;
map<int, int> components;
map<pii,map<int, vector<int>>> G;
map<pii, set<int>> visitedComponent;
int componentNum;
int dy[4]={1, 0, -1, 0}, dx[4]={0, 1, 0, -1};

void swap(int &a, int &b) {
	int t=a;
	a=b;
	b=t;
}

void addEdge(int cmp1, int cmp2, int b1, int b2) {
	if(b1>b2) swap(cmp1, cmp2), swap(b1, b2);
	G[{b1, b2}][cmp1].push_back(cmp2);
	G[{b1, b2}][cmp2].push_back(cmp1);
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	int N, ans1=0, ans2=0;
	cin >> N;
	b=vector<vector<int>>(N, vector<int>(N));
	compID=vector<vector<int>>(N, vector<int>(N));
	vector<vector<bool>> visited(N, vector<bool>(N, false));
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) cin >>b[i][j];
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) {
		if(visited[i][j]==false) {
			visited[i][j]=true;
			queue<pii> q;
			int size=0;
			q.push({i,j});
			while(!q.empty()) {
				int y=q.front().first, x=q.front().second;
				compID[y][x]=componentNum;
				++size;
				q.pop();
				for(int i=0; i<4; ++i) {
					int ny=y+dy[i], nx=x+dx[i];
					if(0<=ny&&ny<N&&0<=nx&&nx<N&&b[ny][nx]==b[y][x]&&visited[ny][nx]==false) {
						visited[ny][nx]=true;
						q.push({ny, nx});
					}
				}
			}
			components[componentNum++]=size;
			ans1=max(ans1, size);
		}
	}
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) {
		if(i+1<N && b[i][j]!=b[i+1][j]) addEdge(compID[i][j], compID[i+1][j], b[i][j], b[i+1][j]);
		if(j+1<N && b[i][j]!=b[i][j+1]) addEdge(compID[i][j], compID[i][j+1], b[i][j], b[i][j+1]);
	}
	for(auto g: G) {
		pii p=g.first;
		for(auto comp: g.second) {
			int u=comp.first;
			if(visitedComponent[p].count(u)==0) {
				int size=0;
				queue<int> q;
				q.push(u);
				visitedComponent[p].insert(u);
				while(!q.empty()) {
					int node=q.front(); q.pop();
					size+=components[node];
					for(int v: g.second[node]) {
						if(visitedComponent[p].count(v)==0) {
							q.push(v);
							visitedComponent[p].insert(v);
						}
					}
				}
				ans2=max(ans2, size);
			}
		}
	}
	cout << ans1 << '\n';
	cout << ans2 << '\n';
}