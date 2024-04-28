#include<iostream>
#include<vector>

using namespace std;

bool inBound(int y, int x, int h, int w) {
	return 0 <= y && y < h && 0 <= x && x < w; 
}

long long calcPath(int W, int H) {
	vector<vector<long long>> dp(H, vector<long long>(W, 0));
	dp[0][0]=1;
	for(int i=0; i<H; ++i) for(int j=0; j<W; ++j) {
		if(inBound(i, j+1, H, W)) dp[i][j+1] += dp[i][j];
		if(inBound(i+1, j, H, W)) dp[i+1][j] += dp[i][j];
	}
	return dp[H-1][W-1];
}

int main(void) {
	int n, m, k;
	cin >> n >> m >> k;
	if(k==0) cout << calcPath(m, n) << '\n';
	else {
		int w=(k-1)%m, h=(k-1)/m;
		cout << calcPath(w+1, h+1) * calcPath(m-w, n-h) << '\n';
	}
}