#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, Q;
	cin >> N >> Q;
	vector<int> pos(N);
	for(int &a: pos) cin >> a;
	sort(pos.begin(), pos.end());
	while(Q--) {
		int a, b;
		cin >> a >> b;
		auto lb=lower_bound(pos.begin(), pos.end(), a), ub=upper_bound(pos.begin(),pos.end(),b);
		cout << ub-lb << '\n';
	}
}