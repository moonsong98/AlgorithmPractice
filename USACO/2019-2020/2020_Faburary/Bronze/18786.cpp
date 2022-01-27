#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

const int SIZE=1e4*2+1;
const int INIT=-1;
const int PUSH=1e4;

typedef struct {
	int x, y;
} point;

int main(void) {
	int n; cin >> n;
	vector<vector<int>> ys(SIZE, vector<int>(2, INIT));
	vector<vector<int>> xs(SIZE, vector<int>(2, INIT));
	vector<point> points(n);

	for(int i=0; i<n; ++i) {
		cin >> points[i].x >> points[i].y;
		if(ys[points[i].x+PUSH][0]==INIT || ys[points[i].x+PUSH][0] < points[i].y) ys[points[i].x+PUSH][0] = points[i].y;
		if(ys[points[i].x+PUSH][1]==INIT || ys[points[i].x+PUSH][1] > points[i].y) ys[points[i].x+PUSH][1] = points[i].y;
		if(xs[points[i].y+PUSH][0]==INIT || xs[points[i].y+PUSH][0] < points[i].x) xs[points[i].y+PUSH][0] = points[i].x;
		if(xs[points[i].y+PUSH][1]==INIT || xs[points[i].y+PUSH][1] > points[i].x) xs[points[i].y+PUSH][1] = points[i].x;
	}
	int ans=0;
	for(int i=0; i<n; ++i) {
		int vert=0, hori=0;
		if(xs[points[i].y+PUSH][0]!=INIT) vert=max(vert, xs[points[i].y+PUSH][0]-points[i].x);
		if(xs[points[i].y+PUSH][1]!=INIT) vert=max(vert, points[i].x-xs[points[i].y+PUSH][1]);
		if(ys[points[i].x+PUSH][0]!=INIT) hori=max(hori, ys[points[i].x+PUSH][0]-points[i].y);
		if(ys[points[i].x+PUSH][1]!=INIT) hori=max(hori, points[i].y-ys[points[i].x+PUSH][1]);
		ans=max(ans, hori*vert);
	}
	cout << ans << '\n';
}