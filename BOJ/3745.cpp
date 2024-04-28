#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int n;
	while(cin >> n) {
		vector<int> seq(n); for(int i=0; i<n; ++i) cin >> seq[i];
		vector<int> dp;
		for(int i=0; i<n; ++i) {
			if(dp.empty() || dp.back()<seq[i]) dp.push_back(seq[i]);
			else *lower_bound(dp.begin(), dp.end(), seq[i])=seq[i];
		}
		cout << dp.size() << '\n';
	}
}