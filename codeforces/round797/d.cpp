#include<bits/stdc++.h>
using namespace std;

const int INF=1e9+7;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		int n, k, ans=INF;
		cin >> n >> k;
		string str;
		cin >> str;
		vector<int> a(n-k+1);
		for(int i=0; i<k; ++i) if(str[i]=='W') a[0]++;
		for(int i=1; i<n-k+1; ++i) {
			a[i]=a[i-1];
			if(str[i-1]=='W') a[i]--;
			if(str[i+k-1]=='W') a[i]++;
		}
		for(int cand:a) ans=min(ans, cand);
		cout << ans << '\n';
	}
}