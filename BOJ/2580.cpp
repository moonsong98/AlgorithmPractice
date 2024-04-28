#include<iostream>
#include<vector>

using namespace std;

vector<bool> row[9];
vector<bool> col[9];
vector<bool> square[9];
vector<vector<int>> board(9, vector<int>(9));

void solution(int y, int x) {
	bool isDone=true;
	if(y==9) {
		for(vector<int> v: board) {
			for(int n: v) cout << n << ' ';
			cout << '\n';
		}
		exit(0);
	}
	if(board[y][x]) {
		x==8?solution(y+1, 0):solution(y,x+1);
		return;
	}
	for(int n=1; n<=9; ++n) {
		if(!row[y][n] && !col[x][n] && !square[(y/3)*3+x/3][n]) {
			board[y][x]=n;
			row[y][n]=col[x][n]=square[(y/3)*3+x/3][n]=true;
			x==8?solution(y+1, 0):solution(y,x+1);
			board[y][x]=0;
			row[y][n]=col[x][n]=square[(y/3)*3+x/3][n]=false;
		}
	}
}

int main(void) {
	for(int i=0; i<9; ++i) {
		row[i]=vector<bool>(9, false);
		col[i]=vector<bool>(9, false);
		square[i]=vector<bool>(9, false);
	}
	for(int i=0; i<9; ++i) for(int j=0; j<9; ++j) {
		cin >> board[i][j];
		row[i][board[i][j]]=true;
		col[j][board[i][j]]=true;
		square[(i/3)*3+j/3][board[i][j]]=true;
	}
	solution(0,0);
}