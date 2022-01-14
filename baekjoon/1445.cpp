#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int dy[]={0,-1,1,0};
int dx[]={-1,0,0,1};

int gy, gx;

typedef struct {
	int g;
	int ng;
	int y;
	int x;
} count;

bool operator > (count a, count b) {
	if(a.g!=b.g) return a.g > b.g;
	if(a.ng!=b.ng) return a.ng > b.ng;
	return abs(a.y-gy) + abs(a.x-gx) > abs(b.y-gy) + abs(b.x-gx);
}

int main(void) {
	int h, w, sy, sx; cin >> h >> w;
	vector<vector<int>> board(h, vector<int>(w,0));
	for(int i=0; i<h; ++i) for(int j=0; j<w; ++j) {
		char a; cin >> a;
		if(a=='S') {
			board[i][j]=10;
			sy=i; sx=j;
		}
		else if(a=='F') {
			board[i][j]=11;
			gy=i; gx=j;
		}
		else if(a=='g') {
			board[i][j]=1;
			for(int k=0; k<8; ++k) {
				int ni=i+dy[k], nj=j+dx[k];
				if(0<=ni&&ni<h&&0<=nj&&nj<w&&board[ni][nj]!=1&&board[ni][nj]!=10&&board[ni][nj]!=11) board[ni][nj]=2;
			}
		}
	}
	vector<vector<count>> counts(h, vector<count>(w));
	priority_queue<count, vector<count>, greater<count>> pq;
	for(int i=0; i<h; ++i) for(int j=0; j<w; ++j) counts[i][j].g=counts[i][j].ng=-1;
	pq.push({0,0,sy,sx});
	while(!pq.empty()) {
		int cy=pq.top().y, cx=pq.top().x, cg=pq.top().g, cng=pq.top().ng; pq.pop();
		if(cy==gy && cx==gx) {
			cout << cg << ' ' << cng << '\n';
			break;
		}
		for(int i=0; i<4; ++i) {
			int ny=cy+dy[i], nx=cx+dx[i];
			if(0<=ny&&ny<h&&0<=nx&&nx<w) {
				if(board[ny][nx]==10) continue;
				if(board[ny][nx]==11) pq.push({cg, cng, ny, nx});
				else {
					int ng=cg, nng=cng;
					if(board[ny][nx]==1) ++ng;
					else if(board[ny][nx]==2) ++nng;
					if(counts[ny][nx].g==-1 || counts[ny][nx].g>ng || counts[ny][nx].ng>nng) {
						counts[ny][nx].g=ng;
						counts[ny][nx].ng=nng;
						pq.push({ng,nng, ny, nx});
					}
				}
			}
		}
	}
	
	// for(int i=0; i<h; ++i)  {
	// 	for(int j=0; j<w; ++j) 
	// 		cout << '(' << counts[i][j].g << ',' << counts[i][j].ng << ')' << ' ';
	// 	cout << '\n';
	// }
}