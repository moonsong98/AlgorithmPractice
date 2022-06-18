#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;


int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	vector<int> nums;
	for(int i=1; i<=4*10000; ++i) {
		string str=to_string(i);
		string revStr=str;
		reverse(revStr.begin(), revStr.end());
		if(str==revStr) nums.push_back(i);
	}
	vector<ll> dp(4*1e4+1, 0);
	dp[0]=1;
	for(int num: nums) {
		for(int i=num; i<=40000; ++i) {
			dp[i]+=dp[i-num];
			if(dp[i]>=MOD) dp[i]%=MOD;
		}
	}

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		cout << dp[n] << '\n';
	}
}