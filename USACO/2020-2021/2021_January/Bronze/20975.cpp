#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
	int n; cin >> n;
	vector<int> a(n); for(int i=0; i<n; ++i) cin >> a[i]; sort(a.begin(), a.end(), greater<int>());
	vector<int> b(n); for(int i=0; i<n; ++i) cin >> b[i];
	vector<int> c(n, 0);
	for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) if(a[i]<=b[j]) ++c[i];
	
	long long ans=1;
	for(int i=0; i<n; ++i) ans*=(c[i]-i);
	cout << ans << '\n';
}