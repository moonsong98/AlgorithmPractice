#include<iostream>

using namespace std;

int board[10][10];

int main(void) {
	int N; cin >> N;
	int ans=0;
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) {
		char ch; cin >> ch;
		board[i][j]=ch-'0';
	}
	for(int a=N-1; a>=0; --a) for(int b=N-1; b>=0; --b)
		if(board[a][b]) {
			++ans;
			for(int c=0; c<=a; ++c) for(int d=0; d<=b; ++d) board[c][d]^=1;
		}
	cout << ans << '\n';
}