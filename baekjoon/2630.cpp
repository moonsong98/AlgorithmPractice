#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> board;
int numZeros, numOnes;

void solve(int y, int x, int size) {
	if(size==1){
		board[y][x] == 0 ? ++numZeros : ++numOnes;
		return;
	}
	int half=size/2;
	int a=board[y][x];
	for(int i=y; i<y+size; ++i) for(int j=x; j<x+size; ++j)
		if(board[i][j]!=a){
			solve(y,x,half);
			solve(y+half,x,half);
			solve(y,x+half,half);
			solve(y+half,x+half,half);
			return;
		}
	a==0?++numZeros:++numOnes;
}

int main(void) {
	int n;
	cin >> n;
	board=vector<vector<int>> (n, vector<int>(n));
	for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) cin >> board[i][j];
	solve(0, 0, n);
	cout << numZeros << '\n';
	cout << numOnes << '\n';
}