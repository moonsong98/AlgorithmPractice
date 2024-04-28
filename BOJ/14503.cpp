#include<iostream>
#include<vector>

using namespace std;
vector<vector<int>> board;
int n, m, ans=0;
int dx[]={0,1,0,-1}, dy[]={-1,0,1,0};

void move(int r, int c, int d) {
	if(board[r][c]==0) {
		board[r][c]=2; ++ans;
	}
	for(int i=d+3; i%4!=d; --i) {
		int nd=i%4, nr=r+dy[nd], nc=c+dx[nd];
		if(board[nr][nc]==0) {
			move(nr, nc, nd);
			return;
		}
	}
	if(board[r+dy[d]][c+dx[d]]==0)
		move(r+dy[d],c+dx[d],d);
	else if(board[r+dy[(d+2)%4]][c+dx[(d+2)%4]]!=1) 
		move(r+dy[(d+2)%4],c+dx[(d+2)%4],d);
}

int main(void) {
	cin >> n >> m;
	board=vector<vector<int>> (n, vector<int>(m,0));
	int r, c, d; cin >> r >> c >> d;
	for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin >> board[i][j];
	move(r, c, d);
	cout << ans << '\n';
}