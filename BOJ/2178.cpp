#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<string>

using namespace std;

int main(void) {
	int n, m;
	int dir[4][2]={{0,1}, {0,-1}, {1,0}, {-1,0}};
	cin >> n >> m;
	vector<vector<char>> b(n+1, vector<char> (m+1));
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j)cin >> b[i][j];
	
	queue<pair<pair<int,int>,int>> q;
	q.push({{1,1},1});
	b[1][1]='0';
	while(!q.empty()) {
		int cy=q.front().first.first, cx=q.front().first.second, cdist=q.front().second; q.pop();
		if(cy==n&&cx==m) {
			cout << cdist << '\n';
			return 0;
		}
		for(int i=0; i<4; ++i) {
			int ny=cy+dir[i][0], nx=cx+dir[i][1], ndist=cdist+1;
			if(1<=ny&&ny<=n&&1<=nx&&nx<=m&&b[ny][nx]=='1') {
				b[ny][nx]='0';
				q.push({{ny,nx},ndist});
			}
		}
	}
}