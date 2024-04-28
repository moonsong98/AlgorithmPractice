#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<vector<int>> board;
int dy[]={0,0,-1,1}, dx[]={1,-1,0,0}, n;

int bfs(bool ill) {
	int ret=0;
	vector<vector<bool>> visited(n, vector<bool>(n,false));
	for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) {
		if(!visited[i][j]) {
			++ret;
			int color=board[i][j];
			queue<pair<int,int>> q;
			q.push({i,j});
			while(!q.empty()) {
				int y=q.front().first, x=q.front().second; q.pop();
				for(int i=0; i<4; ++i) {
					int ny=y+dy[i], nx=x+dx[i];
					if(0<=ny&&ny<n&&0<=nx&&nx<n&&!visited[ny][nx]) {
						if(ill) {
							if(color>0&&board[ny][nx]>0 || color==0&&board[ny][nx]==0){
								visited[ny][nx]=true;
								q.push({ny,nx});
							}
						}
						else {
							if(color==board[ny][nx]) {
								visited[ny][nx]=true;
								q.push({ny,nx});
							}
						}
					}
				}
			}
		}
	}
	return ret;
}

int main(void) {
	cin >> n;
	board=vector<vector<int>>(n,vector<int>(n));
	for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) {
		char a; cin >> a;
		if(a=='B') board[i][j]=0;
		if(a=='G') board[i][j]=1;
		if(a=='R') board[i][j]=2;
	}
	cout << bfs(false) << ' ' << bfs(true) << '\n';
}