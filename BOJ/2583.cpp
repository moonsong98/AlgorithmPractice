	#include<iostream>
	#include<vector>
	#include<queue>
	#include<utility>
	#include<algorithm>

	using namespace std;

	int main(void) {
		int h, w, n, ansCnt=0;
		vector<int> ans;
		int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
		cin >> h >> w >> n;
		vector<vector<int>> b(h, vector<int>(w));
		for(int i=0; i<n; ++i) {
			int x1,x2,y1,y2;
			cin >>x1>>y1>>x2>>y2;
			for(int y=y1; y<y2; ++y) for(int x=x1;x<x2;++x) b[y][x]=1;
		}
		for(int i=0; i<h; ++i)for(int j=0; j<w; ++j){
			if(!b[i][j]) {
				int c=1;
				queue<pair<int,int>> q;
				q.push({i,j});
				b[i][j]=1;
				ansCnt++;
				while(!q.empty()){
					int cy=q.front().first, cx=q.front().second;
					q.pop();
					for(int d=0; d<4; ++d) {
						int ny=cy+dir[d][0], nx=cx+dir[d][1];
						if(0<=ny&&ny<h&&0<=nx&&nx<w&&!b[ny][nx]) {
							c++;
							q.push({ny,nx});
							b[ny][nx]=1;
						}
					}
				}
				ans.push_back(c);
			}
		}
		cout << ansCnt << '\n';
		sort(ans.begin(), ans.end());
		for(int a: ans) cout << a << ' ';
		cout << '\n';
	}