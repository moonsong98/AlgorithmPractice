#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		int n, m, ans=0;
		cin >> n >> m;
		vector<int> v(n);
		for(int &num: v) cin >> num;
		for(int num: v) {
			if(m<num) {
				ans+=num-m;
				m=0;
			}
			else m-=num;
		}
		cout << ans << '\n';
	}
}