#include<iostream>
#include<vector>
#include<utility>
#include<queue>

using namespace std;

int inbound(int y, int x, int H, int W) {
	return 1<=y && y<=H && 1<=x && x <= W;
}

int main(void){ 
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int H, W;
	int dir[4][2]={{0,1}, {1,0}, {0,-1}, {-1,0}};
	cin >> H >> W;
	vector<vector<int>> board(H+1,vector<int>(W+1));
	vector<vector<vector<int>>> dist (H+1, vector<vector<int>>(W+1, vector<int>(2, -1)));
	queue<pair<pair<int,int>,int>> q;
	for(int i=1; i<=H; ++i) for(int j=1; j<=W; ++j) {
		char a;
		cin>>a;
		board[i][j]=a-'0';
	}
	q.push({{1,1},0});
	dist[1][1][0]=1;
	if(H==1 && W==1) {
		cout << 1 << '\n';
		return 0;
	}
	while(!q.empty()) {
		int curY=q.front().first.first, curX=q.front().first.second, used=q.front().second;
		int curDist=dist[curY][curX][used];
		q.pop();
		for(int i=0; i<4; ++i) {
			int nextY=curY+dir[i][0], nextX=curX+dir[i][1];
			if(nextY==H && nextX==W) {
				cout << curDist+1 << '\n';
				return 0;
			}
			if(inbound(nextY, nextX, H, W)) {
				if(dist[nextY][nextX][used]!=-1) continue;
				if(!board[nextY][nextX]) {
					dist[nextY][nextX][used] = curDist+1;
					q.push({{nextY, nextX}, used});
				}
				if(!used) {
					dist[nextY][nextX][1]=curDist+1;
					q.push({{nextY, nextX}, 1});
				}
			}	
		}
	}
	cout << -1;
}