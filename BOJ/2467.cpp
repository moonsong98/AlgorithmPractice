#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;

const ll INF=987654321987654321;

ll abs(const ll& a, const ll& b) {
	return a+b>0 ? a+b : a-b;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<ll> seq(n); for(int i=0; i<n; ++i) cin >> seq[i];
	ll ans[2], minSum=INF;
	int l=0, r=n-1;
	while(l<r) {
		ll sum=seq[l]+seq[r];
		if(abs(sum) < abs(minSum)) {
			minSum=sum;
			ans[0]=seq[l];
			ans[1]=seq[r];
		}
		if(abs(seq[l+1]+seq[r]) < abs(seq[l]+seq[r-1]))
			l=l+1;
		else r=r-1;
	}
	cout << ans[0] << ' ' << ans[1] << '\n';
}