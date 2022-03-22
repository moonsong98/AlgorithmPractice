#include<bits/stdc++.h>
#define X first  
#define Y second 

using namespace std;
typedef pair<int,int> pii;

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
		pii cur=q.front();
		q.pop();
		for(pii p: switches[cur.X][cur.Y]) {
			int x=p.X, y=p.Y;
			if(!isOn[x][y]) {
				isOn[x][y]=true;
				++ans;
				for(int i=0; i<4; ++i) {
					int ny=y+dy[i], nx=x+dx[i];
					if(!inBound(ny, nx)) continue;
					if(found[nx][ny]) {
						q.push({x, y});
						found[x][y]=true;
						break;
					}
				}
			}
		}
		for(int i=0; i<4; ++i) {
			int y=cur.Y+dy[i], x=cur.X+dx[i];
			if(!inBound(y, x)) continue;
			if(isOn[x][y]&&!found[x][y]) {
				q.push({x, y});
				found[x][y]=true;
			}
		}
	}
	cout << ans << '\n';
}