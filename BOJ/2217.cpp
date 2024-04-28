#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
	int n, ans=0;
	cin >> n;
	vector<int> w(n);
	for(int i=0; i<n; ++i)
		cin >> w[i];
	sort(w.begin(), w.end());
	for(int i=0; i<n; ++i)
		ans=max(ans, w[i]*(n-i));
	cout << ans << '\n';
}