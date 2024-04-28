#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int H, W;
vector<vector<char>> board;
vector<vector<int>> minOpen;
vector<vector<int>> minOpenA;
vector<vector<int>> minOpenB;
int dy[4]={0, 1, 0, -1};
int dx[4]={1, 0, -1, 0};
const int INF=1e7;

bool inBound(int y, int x) {
	return 0<=y&&y<H&&0<=x&&x<W;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t; cin >> t;
	while(t--) {
		cin >> H >> W;
		board=vector<vector<char>>(H, vector<char>(W));
		minOpen=vector<vector<int>>(H, vector<int>(W, INF));
		minOpenA=vector<vector<int>>(H, vector<int>(W, INF));
		minOpenB=vector<vector<int>>(H, vector<int>(W, INF));
		pii startPos[2]={{-1,-1}, {-1,-1}};
		priority_queue<pair<int, pii>> pq;
		for(int i=0; i<H; ++i) for(int j=0; j<W; ++j) {
			cin >> board[i][j];
			if(board[i][j]=='$') {
				if(startPos[0].first==-1) startPos[0]={i, j};
				else startPos[1]={i, j};
			}
		}
		for(int i=0; i<W; ++i) {
			if(board[0][i]=='.'||board[0][i]=='$') {
				pq.push({0, {0, i}});
				minOpen[0][i]=0;
			}
			if(board[H-1][i]=='.'||board[H-1][i]=='$'){
				pq.push({0, {H-1, i}});
				minOpen[H-1][i]=0;
			}
			if(board[0][i]=='#'){
				pq.push({-1, {0, i}});
				minOpen[0][i]=1;
			}
			if(board[H-1][i]=='#'){
				pq.push({-1, {H-1, i}});
				minOpen[H-1][i]=1;
			}
		}
		for(int i=1; i+1<H; ++i) {
			if(board[i][0]=='.'||board[i][0]=='$') {
				pq.push({0, {i, 0}});
				minOpen[i][0]=0;
			}
			if(board[i][W-1]=='.'||board[i][W-1]=='$'){
				pq.push({0, {i, W-1}});
				minOpen[i][W-1]=0;
			}
			if(board[i][0]=='#'){
				pq.push({-1, {i, 0}});
				minOpen[i][0]=1;
			}
			if(board[i][W-1]=='#'){
				pq.push({-1, {i, W-1}});
				minOpen[i][W-1]=1;
			}
		}
		while(!pq.empty()) {
			int cost=-pq.top().first, y=pq.top().second.first, x=pq.top().second.second;
			pq.pop();
			if(cost>minOpen[y][x]) continue;
			for(int i=0; i<4; ++i) {
				int ny=y+dy[i], nx=x+dx[i];
				if(!inBound(ny,nx)||board[ny][nx]=='*') continue;
				int nxtCost=cost+(board[ny][nx]=='#');
				if(minOpen[ny][nx]>nxtCost) {
					minOpen[ny][nx]=nxtCost;
					pq.push({-nxtCost,{ny,nx}});
				}
			}
		}
		int ans=minOpen[startPos[0].first][startPos[0].second]+minOpen[startPos[1].first][startPos[1].second];
		pq.push({0, {startPos[0].first,startPos[0].second}});
		while(!pq.empty()) {
			int cost=-pq.top().first, y=pq.top().second.first, x=pq.top().second.second;
			pq.pop();
			if(cost>minOpenA[y][x]) continue;
			for(int i=0; i<4; ++i) {
				int ny=y+dy[i], nx=x+dx[i];
				if(!inBound(ny,nx)||board[ny][nx]=='*') continue;
				int nxtCost=cost+(board[ny][nx]=='#');
				if(minOpenA[ny][nx]>nxtCost) {
					minOpenA[ny][nx]=nxtCost;
					pq.push({-nxtCost,{ny,nx}});
				}
			}
		}
		pq.push({0, {startPos[1].first,startPos[1].second}});
		while(!pq.empty()) {
			int cost=-pq.top().first, y=pq.top().second.first, x=pq.top().second.second;
			pq.pop();
			if(cost>minOpenB[y][x]) continue;
			for(int i=0; i<4; ++i) {
				int ny=y+dy[i], nx=x+dx[i];
				if(!inBound(ny,nx)||board[ny][nx]=='*') continue;
				int nxtCost=cost+(board[ny][nx]=='#');
				if(minOpenB[ny][nx]>nxtCost) {
					minOpenB[ny][nx]=nxtCost;
					pq.push({-nxtCost,{ny,nx}});
				}
			}
		}
		for(int i=0; i<H; ++i) for(int j=0; j<W; ++j) {
			if(board[i][j]=='*') continue;
			ans=min(ans, minOpenA[i][j]+minOpenB[i][j]+minOpen[i][j]-(board[i][j]=='#')*2);
		}
		cout << ans << '\n';
	}
}
