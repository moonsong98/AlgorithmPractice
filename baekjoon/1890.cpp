#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> board;
vector<vector<long long>> dp;
int n;
int dir[2][2]={{1,0}, {0,1}};

long long solution(int y, int x) {
	if(y==n-1 && x==n-1) return 1;
	long long& ret=dp[y][x];
	if(ret!=-1) return ret;
	dp[y][x]=0;
	for(int i=0; i<2; ++i) {
		int nextY=y+dir[i][0]*board[y][x], nextX=x+dir[i][1]*board[y][x];
		if(0<=nextY&&nextY<n && 0<=nextX&&nextX<n)
			dp[y][x]+=solution(nextY, nextX);
	}
	return ret;
}

int main(void) {
	cin >> n;
	board=vector<vector<int>>(n, vector<int>(n));
	dp=vector<vector<long long>>(n, vector<long long>(n, -1));
	for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) cin >> board[i][j];
	cout << solution(0, 0) << '\n';
}
