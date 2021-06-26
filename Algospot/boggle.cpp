#include<iostream>
#include<string>
#include<cstring>

using namespace std;

char board[5][5];
string words[10];
int cache[5][5][11];
int wordIdx;
int movement[8][2] = {{-1,-1}, {-1,0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

bool outOfMap(int y, int x) {
	return y >= 5 || y < 0 || x >= 5 || x < 0;
}

bool hasWord(int y, int x, int idx) {
	//cout << words[wordIdx] << " wordIdx: " << wordIdx << " " << "idx: " << idx << endl;
	if(idx == words[wordIdx].size()-1) return true;
	int& ret = cache[y][x][idx];
	if(ret != -1) return ret;
	
	for(int i = 0; i < 8; ++i) {
		int nextY = y + movement[i][0], nextX = x + movement[i][1];
		if(outOfMap(nextY, nextX)) continue;
		//cout << "nextY " << nextY << " nextX " << nextX << endl;
		if(board[nextY][nextX] == words[wordIdx][idx+1] && hasWord(nextY, nextX, idx+1)) return ret = 1;
	}
	return ret = 0;
}

bool boggle() {
	for(int i = 0; i < 5; ++i) 
		for(int j = 0; j < 5; ++j)
			if(board[i][j] == words[wordIdx][0] && hasWord(i, j, 0))
				return true;
	return false;
}

void solve() {
	for(int i = 0; i < 5; ++i)
		for(int j = 0; j < 5; ++j)
			cin >> board[i][j];
	
	int numWords;	
	cin >> numWords;
	
	for(int i = 0; i < numWords; ++i) {
		cin >> words[i];
		cout << words[i] << " ";	
		wordIdx = i;
		memset(cache, -1, sizeof(cache));
		if(boggle()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}

int main(void) {
	cin.sync_with_stdio(false);
	int t;
	cin >> t;	
	while(t--) solve();
}