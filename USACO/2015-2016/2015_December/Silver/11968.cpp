#include<bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	set<int> nums;
	vector<int> opp(n);
	for(int i=1; i<=n*2; ++i) nums.insert(i);
	for(int i=0; i<n; ++i) {
		cin >> opp[i];
		nums.erase(nums.find(opp[i]));
	}
	int ans=0;
	for(int i=0; i<n; ++i) {
		auto lb=nums.lower_bound(opp[i]);
		if(lb==nums.end()) nums.erase(nums.begin());
		else {
			nums.erase(*lb);
			++ans;
		}
	}
	cout << ans << '\n';
}