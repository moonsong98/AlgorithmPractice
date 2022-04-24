#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
typedef pair<int,int> pii;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<pii> intervals;
	for(int i=0; i<M; ++i) {
		int l, r;
		cin >> l >> r;
		intervals.push_back({l, r});
	}
	sort(intervals.begin(), intervals.end());
	int l=1,r=(intervals.back().second-intervals[0].first)/(N-1), ans=0;
	while(l<=r) {
		int mid=l+(r-l)/2;
		int cnt=1, i=0, cur=intervals[0].first;
		while(true) {
			while(i<sz(intervals) && cur+mid>intervals[i].second)
				++i;
			if(i>=sz(intervals)) break;
			if(cur+mid<intervals[i].first) cur=intervals[i].first;
			else cur+=mid;
			++cnt;
		}
		if(cnt>=N) {
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout << ans << '\n';
}
