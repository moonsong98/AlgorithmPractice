#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

vector<vector<int>> board;
vector<vector<bool>> found;
vector<pii> posVirus;
int H, W, ans;
int dy[4]={1,0,-1,0}, dx[4]={0,1,0,-1};

int solve(int left, int pos) {
	if(left==0) {
		int cnt=0;
		for(int i=0; i<H; ++i) 
			fill(found[i].begin(), found[i].end(), false);
		queue<pii> q;
		for(auto p: posVirus)
			q.push({p.first, p.second});	
		while(!q.empty()) {
			int y=q.front().first, x=q.front().second;
			q.pop();
			for(int k=0; k<4; ++k) {
				int ny=y+dy[k], nx=x+dx[k];
				if(0>ny||ny>=H||0>nx||nx>=W) continue;
				if(board[ny][nx]==0&&found[ny][nx]==false) {
					found[ny][nx]=true;
					q.push({ny,nx});
				}
			}
		}
		for(int i=0; i<H; ++i)
			for(int j=0; j<W; ++j)
				cnt+=(board[i][j]==0&&found[i][j]==false);
		return cnt;
	}
	int ret=0;
	while(pos<H*W) {
		int y=pos/W, x=pos%W;
		if(board[y][x]==0) {
			board[y][x]=1;
			ret=max(ret,solve(left-1, pos+1));
			board[y][x]=0;
		}
		++pos;
	}
	return ret;
}

int main(void) {
	cin >> H >> W;
	board=vector<vector<int>>(H, vector<int>(W));
	found=vector<vector<bool>>(H, vector<bool>(W, false));
	for(int i=0; i<H; ++i)
		for(int j=0; j<W; ++j) {
			cin >> board[i][j];
			if(board[i][j]==2)
				posVirus.push_back({i, j});
		}
	cout << solve(3, 0) << '\n';
}