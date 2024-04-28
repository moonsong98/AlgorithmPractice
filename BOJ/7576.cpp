#include<iostream>
#include<queue>
#include<vector>
#include<utility>

using namespace std;

int main(void) {
	int w, h;
	cin >> w >> h;
	int ans=0;
	int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
	vector<vector<int>> b=vector<vector<int>>(h,vector<int>(w));
	queue<pair<pair<int,int>,int>> q;
	for(int i=0; i<h; ++i) for(int j=0; j<w; ++j) {
		cin>>b[i][j];
		if(b[i][j]==1) q.push({{i,j}, 0});
	}
	while(!q.empty()) {
		int y=q.front().first.first, x=q.front().first.second, d=q.front().second;
		q.pop();
		for(int i=0; i<4; ++i){
			int ny=y+dir[i][0],nx=x+dir[i][1],nd=d+1;
			if(0<=ny&&ny<h&&0<=nx&&nx<w&&!b[ny][nx]){
				b[ny][nx]=1;
				q.push({{ny,nx}, nd});
				ans=max(ans,nd);
			}
		}
	}
	for(int i=0;i<h;++i)for(int j=0; j<w; ++j) if(!b[i][j]) {
		cout << -1 <<'\n';
		return 0;
	}
	cout << ans << '\n';
}