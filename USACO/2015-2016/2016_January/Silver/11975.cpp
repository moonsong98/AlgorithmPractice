#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define sz(x) (int)x.size()
typedef pair<int,int> pii;

int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
set<pair<pii,pii>> e;
set<pii> v;

int main(void) {
	int N, y=0, x=0;
	cin >> N;
	v.insert({0,0});
	for(int i=0; i<N; ++i) {
		char ch; cin >> ch;
		if(ch=='N') {
			e.insert({{y, y+1}, {x, x}});
			v.insert({y+1, x});
			++y;
		}
		else if(ch=='W') {
			e.insert({{y,y},{x-1, x}});
			v.insert({y,x-1});
			--x;
		}
		else if(ch=='E') {
			e.insert({{y,y},{x, x+1}});
			v.insert({y,x+1});
			++x;
		}
		else if(ch=='S') {
			e.insert({{y-1, y},{x,x}});
			v.insert({y-1, x});
			--y;
		}
	}
	cout << sz(e)-sz(v)+1 << '\n';
}

/*
bool board[4001][4001];
bool found[4001][4001];

int main(void) {
	int N;
	cin >> N;
	int y=2000, x=2000;
	for(int i=0; i<N; ++i) {
		char ch;
		cin >> ch;
		if(ch=='N') {
			board[y-1][x]=board[y-2][x]=true;
			y-=2;
		}
		else if(ch=='W') {
			board[y][x-1]=board[y][x-2]=true;
			x-=2;
		}
		else if(ch=='E') {
			board[y][x+1]=board[y][x+2]=true;
			x+=2;
		}
		else if(ch=='S') {
			board[y+1][x]=board[y+2][x]=true;
			y+=2;
		}
	}
	queue<pii> q;
	int ans=-1;
	for(int i=0; i<=4000; ++i) 
		for(int j=0; j<=4000; ++j) {
			if(!found[i][j]&&!board[i][j]) {
				found[i][j]=true;
				++ans;
				q.push({i, j});
				while(!q.empty()) {
					y=q.front().fi, x=q.front().se;
					q.pop();
					for(int i=0; i<4; ++i) {
						int ny=y+dy[i], nx=x+dx[i];
						if(0<=ny&&ny<=4000&&0<=nx&&nx<=4000&&board[ny][nx]==false&&!found[ny][nx]) {
							found[ny][nx]=true;
							q.push({ny,nx});
						}
					}
				}
			}
		}
	cout << ans << '\n';
}
*/