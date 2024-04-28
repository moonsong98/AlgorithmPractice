#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int dy[]={0, 1, 0, -1};
int dx[]={1, 0, -1, 0};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	int H, W;
	cin >> H >> W;
	vector<vector<bool>> board(H, vector<bool>(W,false));
	vector<vector<bool>> visited(H, vector<bool>(W, false));
	vector<vector<int>> whenMelt(H, vector<int> (W, -1));
	vector<pii> pos;
	for(int i=0; i<H; ++i) for(int j=0; j<W; ++j) {
		char ch; cin >> ch;
		if(ch=='X') board[i][j]=true;
		else if(ch=='L') pos.push_back({i, j});
	}
	auto inBound=[=](int y, int x)->bool {
		return 0<=y&&y<H&&0<=x&&x<W;
	};
	for(int i=0; i<H; ++i) for(int j=0; j<W; ++j) if(board[i][j]==false) whenMelt[i][j]=0;
	queue<pair<int,pii>> q;
	for(int i=0; i<H; ++i) for(int j=0; j<W; ++j)
		if(board[i][j]==false)
			for(int k=0; k<4; ++k) {
				int ny=i+dy[k], nx=j+dx[k];
				if(inBound(ny,nx)&&board[ny][nx]==true) {
					q.push({0,{i, j}});
					break;
				}
			}
	int l=0, r=-1;
	while(!q.empty()) {
		int day=q.front().first, y=q.front().second.first, x=q.front().second.second;
		q.pop();
		for(int i=0; i<4; ++i) {
			int ny=y+dy[i], nx=x+dx[i];
			if(inBound(ny, nx)&&whenMelt[ny][nx]==-1) {
				whenMelt[ny][nx]=day+1;
				q.push({day+1, {ny, nx}});
				r=max(r, day+1);
			}
		}
	}
	int ans;
	while(l<=r) {
		queue<pii> q;
		int mid=l+(r-l)/2;
		bool canMeet=false;
		q.push(pos[0]);
		for(int i=0; i<H; ++i) fill(visited[i].begin(), visited[i].end(), false);
		visited[pos[0].first][pos[0].second]=true;
		while(!q.empty()) {
			int y=q.front().first, x=q.front().second; q.pop();
			for(int i=0; i<4; ++i) {
				int ny=y+dy[i], nx=x+dx[i];
				if(inBound(ny, nx)&&!visited[ny][nx]&&whenMelt[ny][nx]<=mid) {
					if(ny==pos[1].first&&nx==pos[1].second) canMeet=true;
					visited[ny][nx]=true;
					q.push({ny, nx});
				}
			}
		}
		if(canMeet) {
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	cout << ans << '\n';
}
