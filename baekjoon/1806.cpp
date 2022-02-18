#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;
const ll INF=1e12;

int n, s;

int main(void) {
	cin >> n >> s;
	vector<int> seq(n);
	for(int i=0; i<n; ++i) cin >> seq[i];
	int left=0, right=0;
	ll ans=INF;
	int sum=0;
	while(left<=right && right <= n) {
		if(sum<s) sum+=seq[right++];
		if(sum>=s) {
			ans=min(ans,(ll)right-left);
			sum-=seq[left++];
		}
	}
	if(ans==INF) ans=0;
	cout << ans << '\n';
}