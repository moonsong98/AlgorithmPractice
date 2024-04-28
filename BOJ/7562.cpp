#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int dir[8][2]={{2,1},{1,2},{-2,1},{-1,2},{2,-1},{1,-2},{-2,-1},{-1,-2}};
	int t;
	cin >> t;
	while(t--) {
		int n, x, y, gx, gy;	
		cin >> n >> y >> x >> gy >> gx;
		queue<pair<pair<int,int>, int>> q;
		vector<vector<int>>visited(n,vector<int>(n, 0));
		q.push({{y,x}, 0});
		visited[y][x]=1;
		while(!q.empty()) {
			int cy=q.front().first.first, cx=q.front().first.second, cc=q.front().second;
			q.pop();
			if(cy==gy&&cx==gx) {
				cout << cc << '\n';
				continue;
			} 
			for(int d=0; d<8; ++d) {
				int ny=cy+dir[d][0], nx=cx+dir[d][1], nc=cc+1;
				if(0<=ny&&ny<n&&0<=nx&&nx<n&&!visited[ny][nx]) {
					q.push({{ny, nx}, nc});
					visited[ny][nx]=1;
				}
			}
		}
	}
}