#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<string>
#include<algorithm>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<string> b(n);
	int ansCnt=0;
	vector<int> ans;
	int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
	for(int i=0; i<n; ++i) cin >> b[i];
	for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) {
		if(b[i][j]=='1') {
			ansCnt++;
			int c=1;
			queue<pair<int,int>> q;
			q.push({i,j});
			b[i][j]='0';
			while(!q.empty()){
				int cy=q.front().first, cx=q.front().second;
				q.pop();
				for(int d=0; d<4; ++d) {
					int ny=cy+dir[d][0], nx=cx+dir[d][1];
					if(0<=ny&&ny<n&&0<=nx&&nx<n&&b[ny][nx]=='1')  {
						b[ny][nx]='0';
						q.push({ny, nx});
						c++;
					}
				}
			}
			ans.push_back(c);
		} 
	}
	sort(ans.begin(), ans.end());
	cout<<ansCnt<<'\n';
	for(int a: ans) cout << a << '\n';
}