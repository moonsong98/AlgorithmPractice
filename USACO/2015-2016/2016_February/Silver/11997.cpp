#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N;
	cin >> N;
	vector<int> y(N), tmpY(N), x(N), tmpX(N);
	for(int i=0; i<N; ++i) {
		cin >> y[i] >> x[i];
		tmpY[i]=y[i], tmpX[i]=x[i];
	}
	sort(tmpY.begin(), tmpY.end());
	sort(tmpX.begin(), tmpX.end());
	tmpY.erase(unique(tmpY.begin(), tmpY.end()), tmpY.end());
	tmpX.erase(unique(tmpX.begin(), tmpX.end()), tmpX.end());
	vector<vector<int>> pSum(sz(tmpY)+1,vector<int>(sz(tmpX)+1,0));
	for(int i=0; i<N; ++i) {
		x[i]=lower_bound(tmpX.begin(), tmpX.end(), x[i])-tmpX.begin();
		y[i]=lower_bound(tmpY.begin(), tmpY.end(), y[i])-tmpY.begin();
		pSum[y[i]+1][x[i]+1]++;
	}
	for(int i=1; i<=sz(tmpY); ++i) for(int j=1; j<=sz(tmpX); ++j) pSum[i][j]=pSum[i][j]+pSum[i-1][j]+pSum[i][j-1]-pSum[i-1][j-1];
	int ans=INT_MAX;
	for(int i=1; i<=sz(tmpY); ++i) for(int j=1; j<=sz(tmpX); ++j) {
		int q2=pSum[i][j];
		int q1=pSum[i][sz(tmpX)]-q2;
		int q3=pSum[sz(tmpY)][j]-q2;
		int q4=pSum[sz(tmpY)][sz(tmpX)]-q1-q3-q2;
		ans=min(ans, max({q1,q2,q3,q4}));
	}
	cout << ans << '\n';
}