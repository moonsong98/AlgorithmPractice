#include<iostream>
#include<vector>

using namespace std;

const int INF=987654321;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, k, b;
	cin >> n >> k >> b;
	vector<bool> isBroken(n+1, false);
	vector<int> cnt(n+1, 0);
	for(int i=0; i<b; ++i) {
		int a;
		cin >> a;
		isBroken[a]=true;
	}
	int ans=INF;
	for(int i=1; i<=n; ++i) {
		cnt[i]+=isBroken[i]+cnt[i-1];
		if(i>=k) {
			cnt[i]-=isBroken[i-k];
			ans=min(ans,cnt[i]);
		}
	}
	cout << ans << '\n';
}