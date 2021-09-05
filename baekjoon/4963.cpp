#include<iostream>
#include<queue>
#include<vector>
#include<utility>

using namespace std;

int main(void) {
	int dir[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
	while(true) {
		int w, h;
		cin >> w >> h;
		if(!w&&!h) return 0;
		vector<vector<int>> b(h,vector<int>(w));
		int ans=0;
		for(int i=0;i<h;++i) for(int j=0;j<w;++j) cin>>b[i][j];
		for(int i=0;i<h;++i) for(int j=0;j<w;++j) {
			if(b[i][j]) {
				ans++;
				queue<pair<int,int>> q;
				q.push({i,j});
				b[i][j]=0;
				while(!q.empty()){
					int y=q.front().first, x=q.front().second;
					q.pop();
					for(int d=0;d<8;++d) {
						int ny=y+dir[d][0], nx=x+dir[d][1];
						if(0<=ny&&ny<h&&0<=nx&&nx<w && b[ny][nx]){
							q.push({ny,nx});
							b[ny][nx]=0;
						}
					}
				}
			}
		}
		cout << ans << '\n';
	}
}