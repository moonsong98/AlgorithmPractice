#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int T; cin >> T;
	while(T--) {
		int N, K, ans=0;
		cin >> N >> K;
		vector<vector<char>>board(N+1, vector<char>(N+1));
		vector<vector<vector<int>>>dp(N+1, vector<vector<int>>(N+1,vector<int>(2, 0))); //count[i][j][d] : d=0: right, d=1: down;
		dp[1][1][0]=dp[1][1][1]=1;
		for(int i=1; i<=N; ++i) for(int j=1; j<=N; ++j) cin >> board[i][j];
		for(int k=0; k<=K; ++k) {
			vector<vector<vector<int>>>tmp(N+1, vector<vector<int>>(N+1,vector<int>(2, 0)));
			for(int i=1; i<=N; ++i) for(int j=1; j<=N; ++j) {
				if(board[i][j]=='H') continue;
				tmp[i][j][k%2]=tmp[i][j-1][k%2]+dp[i][j-1][k%2];
				tmp[i][j][(k+1)%2]=tmp[i-1][j][(k+1)%2]+dp[i-1][j][(k+1)%2];
			}
			for(int i=1; i<=N; ++i) for(int j=1; j<=N; ++j) {
				dp[i][j][0]=tmp[i][j][0];
				dp[i][j][1]=tmp[i][j][1];
			}
			ans+=(dp[N][N][0]+dp[N][N][1]);
		}
		cout << ans << '\n';
	}
}