#include<iostream>

using namespace std;

int H, W;
int block[4][3][2] = {
	{{0,0}, {0,1}, {1,0}},
	{{0,0}, {0,1}, {1,1}},
	{{0,0}, {1,0}, {1,-1}},
	{{0,0}, {1,0}, {1,1}}
};


bool ableToSet(bool board[20][20], int blockType, int y, int x) {
	for(int i = 0; i < 3; ++i) {
		int nextY = y + block[blockType][i][0];
		int nextX = x + block[blockType][i][1];
		if(board[nextY][nextX] || nextY < 0 || nextY >= H || nextX < 0 || nextX >= W)
			return false;
	}
	return true;
}

void setBlock(bool board[20][20], int blockType, int y, int x, bool cover) {
	for(int i = 0; i < 3; ++i) {
		int nextY = y + block[blockType][i][0];
		int nextX = x + block[blockType][i][1];
		board[nextY][nextX] = cover;
	}
}


int coverBoard(bool board[20][20]) {
	int x = -1, y = -1;
	
	for(int i = 0; i < H; ++i) {
		for(int j = 0; j < W; ++j){
			if(!board[i][j]) {
				y = i, x= j;
				break;
			}
		}
		if(y != -1) break;
	}
	
	if(y == -1) return 1;
	
	int ret = 0;
	
	for(int blockType = 0; blockType < 4; ++blockType) {
		if(ableToSet(board, blockType, y, x)) {
			setBlock(board, blockType, y, x, true);
			ret += coverBoard(board);
			setBlock(board, blockType, y, x, false);
		}
	}
	
	return ret;
}

void solve() {
	cin >> H >> W;	
	bool board[20][20];
	
	for(int i = 0; i < H; ++i)
		for(int j = 0; j < W; ++j) {
			char c;
			cin >> c;
			board[i][j] = (c == '#');
		}
	
	cout << coverBoard(board) << endl;
}

int main(void) {
	cin.sync_with_stdio(false);
	
	int t;
	cin >> t;
	while(t--) solve();
}
