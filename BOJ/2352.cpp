#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	int n; cin >> n;
	vector<int> ports(n); for(int i=0; i<n; ++i) cin >> ports[i];
		
	vector<int> dp(1,987654321);
	for(int i=0; i<n; ++i) {
		int cur = ports[i];
		if(cur > dp.back()) dp.push_back(cur);
		else *lower_bound(dp.begin(), dp.end(), cur) = cur;
	}
	cout << dp.size() << '\n';
}