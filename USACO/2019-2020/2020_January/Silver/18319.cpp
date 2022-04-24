#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int &a: v) cin >> a;
	int M=*max_element(all(v)), ans=-1;
	for(int c=1; c<=M; ++c) {
		int cnt=0;
		for(int i=0; i<n; ++i) cnt+=v[i]/c;
		if(cnt<=k/2) continue;
		if(cnt>=k) {
			ans=max(ans, c*k/2);
			continue;
		}
		sort(all(v), [=](int a, int b)->bool {return a%c>b%c;});
		int cand=(cnt-k/2)*c;
		for(int i=0; i<n&&i+cnt<k; ++i)
			cand+=v[i]%c;
		ans=max(ans, cand);
	}
	cout << ans << '\n';
}