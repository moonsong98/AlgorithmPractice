#include<iostream>

using namespace std;

int n;
int board[101][101];
int cache[101][101];

bool jump(int y, int x) {
	if(y == n-1 && x == n-1) return true;
	if(y >= n || x >= n) return false;
	int& ret = cache[y][x];
	return ret = jump(y + board[y][x], x) || jump(y, x + board[y][x]);
}

void solve() {
	cin >> n;	
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j) {
			cin >> board[i][j];
			cache[i][j] = -1;
		}
	
	cout << (jump(0, 0) ? "YES" : "NO" )<< endl;
}

int main(void) {
	cin.sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) solve();
}