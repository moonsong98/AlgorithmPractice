#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int r, c, day=0;
vector<vector<char>> board;
int dy[]={0,0,-1,1}, dx[]={-1,1,0,0};
queue<pair<int,pair<int,int>>> fQ;	

void updateBoard() {
	while(!fQ.empty()&&fQ.front().first<day) {
		int curDay=fQ.front().first, y=fQ.front().second.first, x=fQ.front().second.second; fQ.pop();
		for(int i=0; i<4; ++i) {
			int ny=y+dy[i], nx=x+dx[i];
			if(ny<0||ny>=r||nx<0||nx>=c) continue;
			if(board[ny][nx]!='#'&&board[ny][nx]!='F') {
				fQ.push({curDay+1, {ny,nx}});
				board[ny][nx]='F';	
			}
		}
	}
}

int main(void) {
	int sy, sx; 
	cin >> r >> c;
	
	queue<pair<int,pair<int,int>>> q;	
	vector<vector<bool>> visited(r, vector<bool>(c,false));
	board=vector<vector<char>>(r, vector<char>(c));
	for(int i=0; i<r; ++i) for(int j=0; j<c; ++j) {
		cin >> board[i][j];
		if(board[i][j]=='J') {
			q.push({0, {i,j}}); visited[i][j]=true;
		}
		else if(board[i][j]=='F') fQ.push({0, {i,j}});
	}
	while(!q.empty()) {
		int curDay=q.front().first, y=q.front().second.first, x=q.front().second.second; q.pop();
		if(curDay==day) {
			day++;
			updateBoard();
		}
		for(int i=0; i<4; ++i) {
			int ny=y+dy[i], nx=x+dx[i];
			if(ny<0||ny>=r||nx<0||nx>=c) {
				cout << day << '\n';
				return 0;
			}
			if(board[ny][nx]!='#'&&board[ny][nx]!='F'&&!visited[ny][nx]) {
				q.push({curDay+1, {ny,nx}});
				visited[ny][nx]=true;	
			}
		}
	}
	cout << "IMPOSSIBLE" << '\n';
}