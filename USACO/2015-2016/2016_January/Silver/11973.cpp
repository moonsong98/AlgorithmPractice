#include<bits/stdc++.h>
using namespace std;

int main(void){
	int N, K;
	cin >> N >> K;
	vector<int> X(N);
	for(int &x: X) cin >> x;
	sort(X.begin(), X.end());
	int l=0, r=1e9, ans=0;
	while(l<=r) {
		int mid=l+(r-l)/2;
		int s=0, cnt=0;
		while(s<N) {
			++cnt;
			int e=s;
			for(;e<N&&X[e]-X[s]<=2*mid;++e);
			s=e;
		}
		if(cnt<=K) {
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	cout << ans << '\n';
}