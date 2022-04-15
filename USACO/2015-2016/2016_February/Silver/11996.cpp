#include<bits/stdc++.h>
using namespace std;

long long sqr(long long n) {
	return n*n;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int &a: arr) cin >> a;
	int lowPos=-1, lowest=INT_MAX, cur=0;
	for(int i=0; i<n; ++i) {
		cur+=arr[i]-1;
		if(cur<lowest) {
			lowest=cur;
			lowPos=i;
		}
	}
	if(lowPos<n-1)
		rotate(arr.begin(), arr.begin()+lowPos+1, arr.end());
	long long ans=0;
	for(long long i=0, j=0; i<n; ++i) {
		ans+=sqr(i-j);
		arr[j]--;
		while(j<n&&arr[j]==0) ++j;
	}
	cout << ans << '\n';
}