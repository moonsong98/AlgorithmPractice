#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int n, m, k; 
	cin >> n >> m >> k;
	vector<vector<char>> board(n*k, vector<char>(m*k));
	for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) {
		char ch; cin >> ch;
		for(int l=i*k; l<(i+1)*k; ++l) for(int h=j*k; h<(j+1)*k; ++h) board[l][h]=ch;
	}
	for(auto row: board) {
		for(auto el: row) cout << el;
		cout << '\n';
	}
}