#include<iostream>

using namespace std;

const int INF=987654321;
char board[51][51];

int calc(int startH, int startW){
	char c=board[startH][startW];
	int ans=0;
	for(int i=0; i<8; ++i)
		for(int j=0; j<8; ++j)
			if(((i+j)%2 && board[startH+i][startW+j]==c) || (!((i+j)%2) && board[startH+i][startW+j]!=c)) ans++;
	if(ans>32) ans=64-ans;
	return ans;
}


int main(void) {
	int H, W;
	cin >> H >> W;
		
	for(int i=0; i<H; ++i) for(int j=0; j<W; ++j) cin >> board[i][j];
	int ans=INF;
	for(int i=0; i<=H-8; ++i)
		for(int j=0; j<=W-8; ++j)
			ans=min(ans, calc(i,j));
	cout << ans << '\n';
}