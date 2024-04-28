#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<vi> vvi;
typedef vector<vector<pair<int,int>>> vvpii;

vector<pii> switches[101][101];
bool isOn[101][101];
bool found[101][101];
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; ++i) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		switches[x][y].push_back({a,b});
	}
	
	auto inBound=[=](int y, int x)->bool{
		return 1<=y&&y<=n&&1<=x&&x<=n;	
	};
	
	int ans=1;
	isOn[1][1]=true;
	found[1][1]=true;
	queue<pii> q;
	q.push({1,1});
	while(!q.empty()) {
		int x=q.front().first, y=q.front().second;
		q.pop();
		for(pii p: switches[x][y]) {
			int nx=p.first, ny=p.second;
			if(!isOn[nx][ny]) {
				isOn[nx][ny]=true;
				++ans;
				for(int i=0; i<4; ++i) {
					int nny=ny+dy[i], nnx=nx+dx[i];
					if(!inBound(nny, nnx)) continue;
					if(isOn[nnx][nny]&&found[nnx][nny]) {
						q.push({nx, ny});
						found[nx][ny]=true;
						break;
					}
				}
				if(found[nx][ny]) {
					for(int i=0; i<4; ++i) {
						int nny=ny+dy[i], nnx=nx+dx[i];
						if(!inBound(nny, nnx)) continue;
						if(isOn[nnx][nny]&&!found[nnx][nny]) {
							q.push({nnx, nny});
							found[nnx][nny]=true;
							break;
						}
					}
				}
			}
		}
	}
	cout << ans << '\n';
}