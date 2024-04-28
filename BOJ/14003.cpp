#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int n, INF=1e9+7; cin >> n;
	vector<int> seq(n), trace(n); for(int i=0; i<n; ++i) cin >> seq[i];
	vector<int> dp(1, INF);
	for(int i=0; i<n; ++i) {
		int cur=seq[i];
		if(cur>dp.back()) {
			dp.push_back(cur);
			trace[i]=dp.size()-1;
		}
		else {
			vector<int>::iterator ptr=lower_bound(dp.begin(), dp.end(), cur);
			*ptr=cur;
			trace[i]=ptr-dp.begin();
		}
	}
	cout << dp.size() << '\n';
	vector<int> ans(dp.size(),-1);
	for(int i=n-1; i>=0; --i) {
		if(trace[i]+1 == ans.size() || ans[trace[i]+1] == -1 || seq[i] < ans[trace[i]+1])
			ans[trace[i]] = seq[i];
		
	}
	for(int n: ans) cout << n << ' ';
	cout << '\n';
}