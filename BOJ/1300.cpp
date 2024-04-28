#include<iostream>

using namespace std;

typedef unsigned long long ull;

int main(void) {
	ull n, k;
	cin >> n >> k;
	ull low=1, high=k;
	ull ans;
	while(low<=high) {
		ull mid = low+(high-low)/2;
		cout << low << " " << high << " " << mid << '\n';
		ull cnt=0;
		for(int i=1; i<=n; ++i) cnt+=min(mid/i, n);
		if(cnt<=k){
			ans=mid;
			low=mid+1;
		} else high=mid-1;
	}
	cout << ans << '\n';
}