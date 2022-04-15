#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	for(int tt=1; tt<=T; ++tt) {
		cout << "Case #"<<tt<<": ";
		int N; cin >> N;
		vector<int> arr(N);
		for(int &a: arr) cin >> a;
		sort(arr.begin(), arr.end());
		int ans=0;
		for(int i=0; i<N; ++i)
			if(arr[i]>=ans+1) ++ans;
		cout << ans << '\n';
	}
	
}