#include<iostream>
#include<algorithm>
#include<vector>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
const ll MAX=2*1e7;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<ll> dp(MAX+1, 0);
	int N, S;
	cin >> N >> S;
	for(int i=0; i<N; ++i)  {
		ll height, price;
		cin >> height >> price;
		dp[height]=max(dp[height], price);
	}
	for(int i=1; i<=MAX; ++i) {
		if(i-S>=1) dp[i]+=dp[i-S];
		dp[i]=max(dp[i-1], dp[i]);
	}
	
	cout << dp[MAX] << '\n';
}