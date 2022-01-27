#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct {
	int x;
	bool infected;
} point;

bool operator < (point& a, point& b) {
	return a.x<b.x;
}

int main(void) {
	int N; cin >> N;
	vector<point> cows(N);
	for(int i=0; i<N; ++i) cin >> cows[i].x >> cows[i].infected;
	sort(cows.begin(), cows.end());
	int R=987654321;
	for(int i=0; i+1<N; ++i) if(cows[i].infected^cows[i+1].infected) R=min(R, cows[i+1].x-cows[i].x);
	bool sameGroup=false;
	int ans=0;
	for(int i=0; i<N; ++i) {
		if(cows[i].infected) {
			++ans;
			for(; i+1<N && cows[i].infected && cows[i+1].infected && cows[i+1].x-cows[i].x<R; ++i){}
		}
	}
	cout << ans << '\n';
}