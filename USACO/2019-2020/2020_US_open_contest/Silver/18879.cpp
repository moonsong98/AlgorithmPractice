#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; cin >> n;
	vector<pii> v;
	vector<int> minY(n), maxY(n);
	for(int i=0; i<n; ++i) {
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}
	sort(v.begin(), v.end(), [](pii a, pii b) {
		if(a.first==b.first) return a.second < b.second;
		return a.first < b.first;
	});
	minY[0]=v[0].second;
	for(int i=1; i+1<n; ++i) minY[i]=min(minY[i-1], v[i].second);
	maxY[n-1]=v[n-1].second;
	for(int i=n-2; i>=1; --i) maxY[i]=max(maxY[i+1], v[i].second);
	int ans=1;
	for(int i=0; i<=n; ++i)
		if(minY[i]>maxY[i+1])
			++ans;
	cout << ans << '\n';
}