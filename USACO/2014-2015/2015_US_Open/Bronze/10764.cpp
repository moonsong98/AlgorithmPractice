#include<iostream>
#include<vector>
#include<map>

using namespace std;

int dy[]={-1,-1,-1,0,0,1,1,1};
int dx[]={-1,0,1,-1,1,-1,0,1};

int main(void) {
	int N, M; cin >> N >> M;
	vector<vector<char>> b(N, vector<char>(M)); 
	map<pair<char,char>, int> p2i;
	
	auto inBound=[=](int y, int x) {
		return 0<=y&&y<N&&0<=x&&x<M;
	};
	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j) cin >> b[i][j];
	for(int y=0; y<N; ++y) for(int x=0; x<M; ++x) for(int i=0; i<8; ++i) {
		int ny=y+dy[i], nny=y+2*dy[i], nx=x+dx[i], nnx=x+2*dx[i];
		if(inBound(ny, nx) && inBound(nny, nnx) && b[y][x]!=b[ny][nx] && b[ny][nx]==b[nny][nnx])
			p2i[{b[y][x], b[ny][nx]}]++;
	}
	int ans=0;
	for(auto it=p2i.begin(); it!=p2i.end(); ++it) {
		auto el=*it;
		if(el.first.first=='M'||el.first.second=='O') continue;
		ans=max(ans, (*it).second);
	}
	cout << ans << '\n';
}