#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

int W, H;
int dir[4][2]={{0,1}, {0,-1}, {1,0}, {-1,0}};
vector<vector<int>> b;

bool inBound(int y, int x) {
	return 0 <= y && y < H && 0 <= x && x < W;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> H >> W;
	b=vector<vector<int>>(H, vector<int>(W));
	for(int i=0; i<H; ++i) for(int j=0; j<W; ++j) cin >> b[i][j];
	int ans = -1, maxDist=-1;
	for(int i=0; i<H; ++i) for(int j=0; j<W; ++j) {
		if(!b[i][j]) continue;
		vector<vector<bool>> visited(H, vector<bool>(W, false));
		queue<pair<pair<int,int>, int>> q;
		visited[i][j]=true;
		q.push({{i,j},0});
		while(!q.empty()) {
			int y = q.front().first.first, x=q.front().first.second, dist=q.front().second;
			q.pop();
			if(dist > maxDist || dist == maxDist && b[i][j] + b[y][x] > ans) {
				ans=b[i][j]+b[y][x];
				maxDist=dist;
			}
			for(int i=0; i<4; ++i) {
				int ny = y+dir[i][0], nx=x+dir[i][1];
				if(inBound(ny, nx) && b[ny][nx] && !visited[ny][nx]) {
					visited[ny][nx]=true;
					q.push({{ny, nx}, dist+1});
				}
			}
		}
	}
	cout << ans << '\n';
}