#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef struct {
	int y;
	int x;
} point;

bool operator < (const point& A, const point& B) {
	if(A.y != B.y) return A.y < B.y;
	return A.x < B.x;
}

vector<int> X;
vector<int> Y;

int main(void) {
	int N, B; cin >> N >> B;
	vector<point> points;
	for(int i=0; i<N; ++i) {
		int a, b; cin >> a >> b;
		X.push_back(a);
		Y.push_back(b);
		points.push_back({b,a});
	}
	sort(X.begin(), X.end()); X.erase(unique(X.begin(), X.end()), X.end());
	sort(Y.begin(), Y.end()); Y.erase(unique(Y.begin(), Y.end()), Y.end());
	auto getX = [&](int x) {
		return lower_bound(X.begin(), X.end(), x) - X.begin();
	};
	auto getY = [&](int y) {
		return lower_bound(Y.begin(), Y.end(), y) - Y.begin();
	};
	vector<vector<int>> cnt(Y.size(), vector<int>(X.size(), 0));
	for(point &p: points) {
		p.y=getY(p.y);
		p.x=getX(p.x);
		cnt[p.y][p.x]=1;
	}
	for(int i=0; i<Y.size(); ++i) for(int j=0; j<X.size(); ++j) {
		if(i>0) cnt[i][j]+=cnt[i-1][j];
		if(j>0) cnt[i][j]+=cnt[i][j-1];
		if(i>0 && j>0) cnt[i][j]-=cnt[i-1][j-1];
	}
	int ans=987564321;
	for(int i=0; i<Y.size(); ++i) for(int j=0; j<X.size(); ++j) 
		ans=min(ans, max({cnt[i][j], cnt[i][X.size()-1]-cnt[i][j], cnt[Y.size()-1][j]-cnt[i][j], cnt[Y.size()-1][X.size()-1]-cnt[i][X.size()-1]-cnt[Y.size()-1][j]+cnt[i][j]}));
	cout << ans << '\n';
}