#include<iostream>
#include<vector>
#include<utility>
#include<queue>

using namespace std;

int main(void) {
	int h, w;
	int dir[5][2]={{0,0}, {0,1}, {0,-1}, {1,0}, {-1,0}};
	cin >> h >> w;
	vector<vector<int>> b(h+1, vector<int>(w+1));
	vector<vector<vector<bool>>> visited(h+1, vector<vector<bool>> (w+1, vector<bool>(5, false)));
	for(int i=1; i<=h; ++i) for(int j=1; j<=w; ++j) cin >> b[i][j];
	int s[3],e[3];
	for(int i=0; i<3; ++i) cin >> s[i];
	for(int i=0; i<3; ++i) cin >> e[i];
	
	queue<pair<pair<pair<int,int>, int>, int>> q;
	q.push({{{s[0],s[1]},s[2]},0});
	visited[s[0]][s[1]][s[2]]=true;
	while(!q.empty()) {
		int cy=q.front().first.first.first, cx=q.front().first.first.second, cdir=q.front().first.second, cc=q.front().second;
		// cout << '[' << cy << ']' << '[' << cx << ']' << " cdir: " << cdir << " cc: " << cc << '\n';
		q.pop();
		if(cy==e[0]&&cx==e[1]&&cdir==e[2]) {
			cout << cc << '\n';
			break;
		}
		// go
		int ny=cy, nx=cx, ndir=cdir, nc=cc+1;
		for(int i=1; i<=3; ++i) {
			ny+=dir[ndir][0], nx+=dir[ndir][1];
			// cout << "ny: " << ny << " nx: " << nx << '\n';
			if(!(1<=ny && ny <= h && 1<=nx && nx<=w) || b[ny][nx]) break;
			if(visited[ny][nx][ndir]) continue; // if it's possible to go but visited just skip and look for the next space;
			q.push({{{ny, nx}, ndir}, nc});
			visited[ny][nx][ndir]=true;
		}
		
		//turn
		ny=cy, nx=cx;
		for(ndir=1; ndir<=4; ++ndir){
			if(cdir<=2 && ndir<=2 || cdir>2 && ndir>2) continue;
			if(visited[ny][nx][ndir]) continue;
			q.push({{{ny, nx}, ndir}, nc});
			visited[ny][nx][ndir]=true;
		}
	}
}