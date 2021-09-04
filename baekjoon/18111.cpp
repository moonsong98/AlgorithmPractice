#include<iostream>

using namespace std;

int board[501][501];

int main(void) {
	int n, m, b;
	int ans[2]={987654321, -1};
	cin >> n >> m >> b;
	for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin >> board[i][j];
	for(int h=0; h<=256; ++h) {
		int t=0, d=0, p=0;
		for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) {
			if(board[i][j]>h) d+=board[i][j]-h;
			else if(board[i][j]<h) p+=h-board[i][j];
		}
		if(d+b<p) continue;
		t=2*d+p;	
		if(t<=ans[0]) {
			ans[0]=t;
			ans[1]=h;
		}
	}
	cout << ans[0] << ' ' << ans[1] << '\n';
}