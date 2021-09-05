#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

int main(void) {
	int t;
	int dir[4][2]={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	cin >> t;
	while(t--) {
		int	h, w, k;
		cin >> w >> h >> k;
		vector<vector<int>> b(h, vector<int>(w, 0));
		for(int i=0; i<k; ++i) {
			int x, y;
			cin >> x >> y;
			b[y][x]=1;
		}
		int ans=0;
		for(int i=0; i<h; ++i) for(int j=0; j<w; ++j) {
			if(b[i][j]) {
				++ans;
				queue<pair<int,int>> q;
				q.push({i, j});
				b[i][j]=0;
				while(!q.empty()) {
					int y=q.front().first, x=q.front().second;
					q.pop();
					for(int i=0; i<4; ++i) {
						int ny=y+dir[i][0], nx=x+dir[i][1];
						if(0<=ny && ny<h && 0<=nx && nx<w && b[ny][nx]) {
							q.push({ny, nx});
							b[ny][nx]=0;
						}
					}
				}
			}
		}
		cout << ans << '\n';
	}
}