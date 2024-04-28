#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int n, INF=1e9+7; cin >> n;
	vector<int> seq(n); for(int i=0; i<n; ++i) cin >> seq[i];
	vector<int> dp(1, INF);
	for(int i=0; i<n; ++i) {
		int cur = seq[i];
		if(cur > dp.back()) dp.push_back(cur);
		else *lower_bound(dp.begin(), dp.end(), cur)=cur;
	}
	cout << dp.size() << '\n';
}