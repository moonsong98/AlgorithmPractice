#include<iostream>
#include<queue>
#include<utility>
#include<vector>

using namespace std;

// N: 0, E: 1, S: 2, W: 3

int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

int main(void){
	int n, k, r; 
	cin >> n >> k >> r;
	vector<vector<int>> adj(n+1, vector<int>(n+1, 15));
	vector<vector<bool>> isCowExist(n+1, vector<bool>(n+1, false));
	vector<vector<bool>> visited(n+1, vector<bool>(n+1, false));
	vector<int> cows(1,0);
	for(int i=0; i<r; ++i) {
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		if(y1==y2) {
			if(x1>x2) {
				adj[y1][x1]-=(1<<3);
				adj[y2][x2]-=(1<<1);
			}
			else {
				adj[y1][x1]-=(1<<1);
				adj[y2][x2]-=(1<<3);
			}
		}
		else {
			if(y1>y2) {
				adj[y1][x1]-=(1<<0);
				adj[y2][x2]-=(1<<2);
			}
			else {
				adj[y1][x1]-=(1<<2);
				adj[y2][x2]-=(1<<0);
			}
		}
	}
	for(int i=0; i<k; ++i) {
		int y, x;
		cin >> y >> x;
		isCowExist[y][x]=true;
	}
	auto inBound=[=](int y, int x) {
		return 1<=y&&y<=n&&1<=x&&x<=n;
	};
	queue<pair<int,int>> q;
	for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) {
		if(visited[i][j]==false) {
			int cnt=0;
			visited[i][j]=true;
			q.push({i,j});
			if(isCowExist[i][j]) ++cnt;
			while(!q.empty()){
				int y=q.front().first, x=q.front().second;
				q.pop();
				for(int i=0; i<4; ++i) {
					if(((1<<i)&adj[y][x])==0) continue;
					int ny=y+dy[i], nx=x+dx[i];
					if(inBound(ny,nx)==false||visited[ny][nx]) continue;
					if(isCowExist[ny][nx]) ++cnt;
					q.push({ny, nx});
					visited[ny][nx]=true;
				}
			}
			cows.push_back(cnt);
		}
	}
	long long ans=0;
	for(int i=0; i<cows.size(); ++i)
		for(int j=i+1; j<cows.size(); ++j)
			ans+=cows[i]*cows[j];
	cout << ans << '\n';
}