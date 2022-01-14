#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

int r, c, day=0;
int dy[]={0,0,-1,1}, dx[]={-1,1,0,0};
vector<vector<char>> board;
queue<pair<int,pair<int,int>>> fQ;

void updateBoard() {
	while(!fQ.empty()&&fQ.front().first<day) {
		int curDay=fQ.front().first, y=fQ.front().second.first, x=fQ.front().second.second; fQ.pop();
		for(int i=0; i<4; ++i) {
			int ny=y+dy[i], nx=x+dx[i];
			if(ny<0||ny>=r||nx<0||nx>=c) continue;
			if(board[ny][nx]!='#'&&board[ny][nx]!='*') {
				board[ny][nx]='*';
				fQ.push({curDay+1, {ny,nx}});
			}
		}
	}
}

int main(void) {
	int t; cin >> t;
	while(t--) {
		bool finished=false;
		day=0;
		cin >> c >> r;
		board=vector<vector<char>>(r,vector<char>(c));	
		queue<pair<int,pair<int,int>>> q;
		fQ=queue<pair<int,pair<int,int>>>();
		vector<vector<bool>> visited(r,vector<bool>(c, false));
		for(int i=0; i<r; ++i) for(int j=0; j<c; ++j) {
			cin >> board[i][j];
			if(board[i][j]=='@') {
				visited[i][j]=true; q.push({0,{i,j}});
			}
			else if(board[i][j]=='*') fQ.push({0,{i,j}});
		}
		while(!q.empty()) {
			int curDay=q.front().first, y=q.front().second.first, x=q.front().second.second; q.pop();
			if(curDay==day) {
				++day;
				updateBoard();
			}
			for(int i=0; i<4; ++i) {
				int ny=y+dy[i], nx=x+dx[i];
				if(ny<0||ny>=r||nx<0||nx>=c) {
					finished=true;
					break;
				}
				if(board[ny][nx]!='#'&&board[ny][nx]!='*'&&!visited[ny][nx]) {
					visited[ny][nx]=true;
					q.push({curDay+1, {ny,nx}});
				}
			}
			if(finished) break;
		}
		if(finished) cout << day << '\n';
		else cout << "IMPOSSIBLE" << '\n';
	}
}