#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

typedef struct {
	int y;
	int x;
} point;

int main(void) {
	int N; cin >> N;
	vector<point> points(N);
	int lengthSum=0;
	for(int i=0; i<N; ++i) cin >> points[i].y >> points[i].x;
	auto dist=[&](int i, int j) {
		return abs(points[i].y-points[j].y)+abs(points[i].x-points[j].x);
	};
	for(int i=0; i+1<N; ++i) lengthSum+=dist(i, i+1);
	int ans=987654321;
	for(int i=1; i+1<N; ++i)
		ans=min(ans, lengthSum-dist(i,i-1)-dist(i,i+1)+dist(i+1,i-1));
	cout << ans << '\n';
}