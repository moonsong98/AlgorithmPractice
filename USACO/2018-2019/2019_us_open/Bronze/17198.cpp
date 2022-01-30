#include<iostream>
#include<queue>
#include<utility>

using namespace std;

int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

int main(void) {
	char board[10][10];
	bool visited[10][10]={false,};
	queue<pair<pair<int,int>, int>> q;
	for(int i=0; i<10; ++i) for(int j=0; j<10; ++j) {
		cin >> board[i][j];
		if(board[i][j]=='L') {
			q.push({{i, j}, 0});
			visited[i][j]=true;
		}
	}
	while(!q.empty()) {
		int y=q.front().first.first, x=q.front().first.second, dist=q.front().second; q.pop();
		if(board[y][x]=='R') continue;
		if(board[y][x]=='B') {
			cout << dist-1 << '\n';
			break;
		}
		for(int i=0; i<4; ++i) {
			int ny=y+dy[i], nx=x+dx[i];
			if(0<=ny&&ny<10&&0<=nx&&nx<10&&!visited[ny][nx]) {
				q.push({{ny,nx}, dist+1});
				visited[ny][nx]=true;
			}
		}
	}
}