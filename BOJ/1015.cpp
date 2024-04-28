#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(void) {
	int n; cin >> n;
	vector<pii> v;
	vector<int> ans(n);
	for(int i=0; i<n; ++i) {
		int a; cin >> a;
		v.push_back({a, i});
	}
	sort(v.begin(), v.end());
	for(int i=0; i<n; ++i)
		ans[v[i].second]=i;
	for(int a: ans) cout << a << ' ';
	cout << '\n';
}