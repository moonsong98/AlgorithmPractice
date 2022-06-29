#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int cnt1=0, cnt2=0;
		for(int i=0; i<n; ++i) {
			int num; cin >> num;
			if(num&1) cnt1++;
			else cnt2++;
		}
		cout << min(cnt1, cnt2) << '\n';
	}
}
