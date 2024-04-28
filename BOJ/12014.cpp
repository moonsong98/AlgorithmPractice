#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	for(int c=1; c<=t; ++c) {
		int n, k; cin >> n >> k;
		vector<int> seq(n); for(int i=0; i<n; ++i) cin>>seq[i];
		vector<int> dp;
		for(int i=0; i<n; ++i) {
			if(dp.empty()||dp.back() < seq[i]) dp.push_back(seq[i]);
			else *lower_bound(dp.begin(), dp.end(), seq[i]) = seq[i];
		}
		cout << "Case #" << c << '\n';
		cout << (k<=dp.size()) << '\n';
	}
}