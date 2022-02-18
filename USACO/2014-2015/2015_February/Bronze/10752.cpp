#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int R, C; cin >> R >> C;
	vector<vector<char>> b(R, vector<char>(C));
	vector<vector<int>> dp(R, vector<int>(C,0));
	for(int r=0; r<R; ++r) for(int c=0; c<C; ++c) cin >> b[r][c];
	dp[R-1][C-1]=1;
	for(int r=R-2; r>=0; --r) for(int c=C-2; c>=0; --c) {
		for(int i=r+1; i<R; ++i) for(int j=c+1; j<C; ++j) if(b[r][c]!=b[i][j]) dp[r][c]+=dp[i][j];
	}
	cout << dp[0][0] << '\n';
}