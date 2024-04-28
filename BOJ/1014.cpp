#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> numOnes;

void init() {
	numOnes=vector<vector<int>> (11);
	for(int i=1; i<=10; ++i) {
		numOnes[i]=vector<int>((1<<i));
		for(int j=1; j<(1<<i); ++j) {
			int cnt=0;
			for(int k=0; k<=i; ++k) 
				if((1<<k)&j) ++cnt;
			numOnes[i][j]=cnt;
		}
	}
}

bool isValid(int x, int y, int w) {
	for(int i=1; i+1<w; ++i) 
		if( ( (1<<i)&x )&&( ((1<<(i+1))&y)||((1<<(i-1))&y) )) return false;
	return true;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	init();
	int t; cin >> t;
	while(t--) {
		int H, W; cin >> H >> W;
		vector<int> board(H);
		vector<vector<int>> dp(H, vector<int>(1<<W, -1));
		for(int i=0; i<H; ++i)
			for(int j=0; j<W; ++j) {
				char ch; cin >> ch;
				if(ch=='x') board[H-i-1]+=(1<<j);
			}
		for(int i=0; i<(1<<W); ++i) 
			if(i==0||!(board[0]&i) && isValid(i, i, W))
				dp[0][i]=numOnes[W][i];
		for(int h=1; h<H; ++h)
			for(int k=0; k<(1<<W); ++k) {
				if(dp[h-1][k]==-1) continue;
				for(int j=0; j<(1<<W); ++j)
					if(j==0||!(board[h]&j)&&isValid(j, j, W)&&isValid(j, k, W)&&isValid(k,j,W))
						dp[h][j]=max(dp[h][j], dp[h-1][k]+numOnes[W][j]);
			}
		int ans=-1;
		for(int i=0; i<(1<<W); ++i)
			ans=max(dp[H-1][i], ans);
		cout << ans << '\n';
	}
}