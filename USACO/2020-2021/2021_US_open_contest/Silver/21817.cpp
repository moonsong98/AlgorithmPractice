#include<bits/stdc++.h>
using namespace std;

struct BoardState {
	bool isEmpty=false, isWall=false;
	char ch;
	int y, x;
};
int dr[4]={-1, 0, 1, 0};
int dc[4]={0, 1, 0, -1};

int n;
vector<vector<BoardState>> board;
vector<vector<bool>> visited;
pair<int,int> startPoint;
int pow3[10]={1,};
set<int> possibleStates;

void init() {
	for(int i=1; i<=9; ++i)
		pow3[i]=pow3[i-1]*3;
}

bool inBound(int r, int c) {
	return 0<=r&&r<n&&0<=c&&c<n;
}

bool canWin(int state) {
	int cells[3][3];
	for(int i=0; i<3; ++i) for(int j=0; j<3; ++j) {
		cells[i][j]=state%3;
		state/=3;
	}
	for(int r=0; r<3; ++r) {
		if(cells[r][0]==1&&cells[r][1]==2&&cells[r][2]==2) return true;
		if(cells[r][0]==2&&cells[r][1]==2&&cells[r][2]==1) return true;
	}
	for(int c=0; c<3; ++c) {
		if(cells[0][c]==1&&cells[1][c]==2&&cells[2][c]==2) return true;
		if(cells[0][c]==2&&cells[1][c]==2&&cells[2][c]==1) return true;
	}
	if(cells[0][0]==1&&cells[1][1]==2&&cells[2][2]==2) return true;
	if(cells[0][0]==2&&cells[1][1]==2&&cells[2][2]==1) return true;
	if(cells[0][2]==1&&cells[1][1]==2&&cells[2][0]==2) return true;
	if(cells[0][2]==2&&cells[1][1]==2&&cells[2][0]==1) return true;
	return false;
}

void dfs(int r, int c, int state) {
	int idx=r*n+c;
	visited[idx][state]=true;
	if(board[r][c].isEmpty==false) {
		char ch=board[r][c].ch;
		int y=board[r][c].y, x=board[r][c].x, boardIdx=3*y+x;
		if((state/pow3[boardIdx])%3==0) {
			state+=pow3[boardIdx]*(ch=='M'?1:2);
			visited[idx][state]=true;
		}
	}
	if(canWin(state)) {
		possibleStates.insert(state);
		return;
	}
	for(int i=0; i<4; ++i) {
		int nr=r+dr[i], nc=c+dc[i], nidx=nr*n+nc;
		if(inBound(nr, nc)&&board[nr][nc].isWall==false&&visited[nidx][state]==false)
			 dfs(nr, nc, state);
	}
}


int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	init();
	cin >> n;
	board=vector<vector<BoardState>>(n, vector<BoardState>(n));
	visited=vector<vector<bool>> (n*n, vector<bool>(pow3[9], false));
	for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) {
		char ch1, ch2, ch3;
		cin >> ch1 >> ch2 >> ch3;
		if(ch1=='#') board[i][j].isWall=true;
		else if(ch1=='.') board[i][j].isEmpty=true;
		else if(ch1=='B') {
			board[i][j].isEmpty=true;
			startPoint.first=i;
			startPoint.second=j;
		}
		else {
			board[i][j].ch=ch1;
			board[i][j].y=ch2-'0'-1;
			board[i][j].x=ch3-'0'-1;
		}
	}
	dfs(startPoint.first, startPoint.second, 0);
	cout << possibleStates.size() << '\n';
}