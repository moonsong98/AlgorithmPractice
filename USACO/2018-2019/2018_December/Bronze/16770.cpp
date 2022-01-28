#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int main(void) {
	int n; cin >> n;
	vector<pair<pair<int,int>, int>> tasks;
	for(int i=0; i<n; ++i) {
		int s, t, b; cin >> s >> t >> b;
		tasks.push_back({{s,t},b});
	}
	int ans=-1;
	for(int i=1; i<=1000; ++i) {
		int cnt=0;
		for(int j=0; j<n; ++j) {
			int s=tasks[j].first.first;
			int t=tasks[j].first.second;
			int b=tasks[j].second;
			if(s<=i&&i<=t) cnt+=b;
		}
		ans=max(ans, cnt);
	}
	cout << ans << '\n';
}