#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
	int N; cin >> N;
	vector<ll> arr(N+1), m(N+1), pSum(N+1);
	for(int i=1; i<=N; ++i) cin >> arr[i];
	m[N]=arr[N];
	for(int i=N-1; i>=1; --i) m[i]=min(m[i+1], arr[i]);
	for(int i=1; i<=N; ++i) pSum[i]=pSum[i-1]+arr[i];
	int pos=1;
	ll val=pSum[N]-pSum[1]-m[2];
	vector<int> cand={1};
	for(int k=2; k<=N-2; ++k) {
		ll cur=pSum[N]-pSum[k]-m[k+1];
		if(cur*(N-pos-1)==val*(N-k-1)) cand.push_back(k);
		else if(cur*(N-pos-1)>val*(N-k-1)){
			val=cur;
			pos=k;
			cand.clear();
			cand.push_back(pos);
		}
	}
	for(int c: cand) cout << c << ' ';
	cout << '\n';
}