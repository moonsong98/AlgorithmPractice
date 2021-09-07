#include<iostream>
#include<queue>
#include<vector>
#include<utility>

using namespace std;

int main(void) {
	int n, minH=987654321, maxH=-1, ans=1;
	int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	cin >> n;
	vector<vector<int>> h(n, vector<int>(n));
	for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) {
		cin >> h[i][j];
		minH=min(minH,h[i][j]);
		maxH=max(maxH,h[i][j]);
	}

	for(int ch=minH; ch<=maxH; ++ch) {
		vector<vector<int>> b(h);
		int cnt=0;
		for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) b[i][j]=b[i][j]<=ch;
		for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) {
			if(!b[i][j]) {
				queue<pair<int,int>> q;
				q.push({i, j});
				b[i][j]=1;
				cnt++;
				while(!q.empty()) {
					int cy=q.front().first, cx=q.front().second; q.pop();
					for(int d=0; d<4; ++d) {
						int ny=cy+dir[d][0], nx=cx+dir[d][1];
						if(0<=ny&&ny<n&&0<=nx&&nx<n&&!b[ny][nx]) {
							q.push({ny, nx});
							b[ny][nx]=1;
						}
					}
				}
			}
		}
		ans=max(ans, cnt);
	}
	cout << ans << '\n';
}