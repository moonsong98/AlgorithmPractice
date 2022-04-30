#include<bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; cin >> n;
	vector<long long> a(n);
	for(int i=0; i<n; ++i) cin >> a[i];
	vector<long long> b(n);
	long long ans=-1;
	for(int i=0; i<n; ++i) {
		long long cnt=0;
		fill(b.begin(), b.end(), 0);
		for(int j=i-1; j>=0; --j) {
			if(j==i-1) {
				b[j]=-a[j];
				++cnt;
			}
			else {
				b[j]=(b[j+1]/a[j]-1)*(a[j]);
				cnt+=-(b[j+1]/a[j]-1);
			}
		}
		for(int j=i+1; j<n; ++j) {
			b[j]=(b[j-1]/a[j]+1)*(a[j]);
			cnt+=(b[j-1]/a[j]+1);
		}
		ans=ans==-1?cnt:min(ans, cnt);
	}
	cout << ans << '\n';
}