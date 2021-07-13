#include<iostream>

using namespace std;

int n;
int board[501][501];
int cache[501][501];

int direction[4][2] = {
	{0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

int panda(int y, int x) {
	int& ret = cache[y][x];
	if(ret != -1) return ret;
	ret = 1;
	for(int i = 0; i < 4; ++i) {
		int nextY = y + direction[i][0], nextX = x + direction[i][1];	
		if(nextY < 0 || nextX < 0 || nextY == n || nextX == n)
			continue;
		if(board[y][x] < board[nextY][nextX])
			ret = max(ret, 1 + panda(nextY, nextX));
	}	
	return ret;
}

int main(void) {
	cin.sync_with_stdio(false);
	cin >> n;
	
	for(int i = 0; i < n; ++i)	
		for(int j = 0; j < n; ++j) {
			cin >> board[i][j];
			cache[i][j] = -1;	
		}
	
	int M = -1;
	
	for(int y = 0; y < n; ++y)
		for(int x = 0; x < n; ++x) {
			M = max(M, panda(y, x));
		}
	
	cout << M << endl;
}