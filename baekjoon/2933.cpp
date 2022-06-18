#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int r, c;
int dy[4]={0, 1, 0, -1}, dx[4]={1, 0, -1, 0};
vector<vector<char>> board;
void print() {
	for(int i=1; i<=r; ++i) {
		for(int j=1; j<=c; ++j) cout << board[i][j];
		if(i<r)
			cout << '\n';
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> r >> c;
	board=vector<vector<char>>(r+1, vector<char>(c+1));
	vector<vector<bool>> visited(r+1);
	for(int i=1; i<=r; ++i) for(int j=1; j<=c; ++j) cin >> board[i][j];
	int n; cin >> n;
	for(int i=0; i<n; ++i) {
		int y, x=-1; cin >> y;
		y=r-y+1;
		if(i%2==0)
			for(int j=1; j<=c; ++j) {
				if(board[y][j]=='x') {
					x=j;
					break;
				}
			}
		else
			for(int j=c; j>=1; --j) {
				if(board[y][j]=='x') {
					x=j;
					break;
				}
			}
		if(x==-1) continue;
		board[y][x]='.';
		fill(visited.begin(), visited.end(), vector<bool>(c+1, false));
		auto inBound=[=](int y, int x)->bool{return 1<=y&&y<=r&&1<=x&&x<=c;};
		for(int i=0; i<4; ++i) {
			if(!inBound(y+dy[i], x+dx[i])||visited[y+dy[i]][x+dx[i]]||board[y+dy[i]][x+dx[i]]=='.') continue;
			bool splitted=true;
			queue<pii> q;
			vector<vector<bool>> comp(r+1, vector<bool>(c+1, false));
			comp[y+dy[i]][x+dx[i]]=true;
			q.push({y+dy[i], x+dx[i]});
			visited[y+dy[i]][x+dx[i]]=true;
			while(!q.empty()) {
				int curY=q.front().first, curX=q.front().second; q.pop();
				for(int i=0; i<4; ++i) {
					int ny=curY+dy[i], nx=curX+dx[i];
					if(inBound(ny, nx)&&visited[ny][nx]==false&&board[ny][nx]=='x'){
						q.push({ny, nx});
						comp[ny][nx]=true;
						visited[ny][nx]=true;
						if(ny==r) {
							splitted=false;
							break;
						}
					}
				}
			}
			if(splitted) {
				int shouldMove=INT_MAX;
				for(int i=1; i<=r; ++i) for(int j=1; j<=c; ++j)
					if(comp[i][j]) {
						int k=i+1;
						for(; k<=r; ++k)
							if(board[k][j]=='x') {
								if(!comp[k][j])
									shouldMove=min(shouldMove, k-i-1);
								break;
							}
						if(k==r+1)
							shouldMove=min(shouldMove, r-i);
					}
				for(int i=1; i<=r; ++i) for(int j=1; j<=c; ++j)
					if(comp[i][j])
						board[i][j]='.';
				for(int i=1; i<=r; ++i) for(int j=1; j<=c; ++j)
					if(comp[i][j])
						board[i+shouldMove][j]='x';
			}
		}
	}
	print();
}