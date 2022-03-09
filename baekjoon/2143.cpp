#include<iostream>
#include<vector>
#include<algorithm>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

int main(void) {
	int G;
	cin >> G;
	int N1, N2;
	cin >> N1;
	vector<ll> A(N1+1);
	for(int i=1; i<=N1; ++i) {
		cin >> A[i];
		A[i]+=A[i-1];
	}
	cin >> N2;
	vector<ll> B(N2+1);
	for(int i=1; i<=N2; ++i) {
		cin >> B[i];
		B[i]+=B[i-1];
	}
	vector<ll> seqA, seqB;
	for(int i=1; i<=N1; ++i) for(int j=i; j<=N1; ++j) 
		seqA.push_back(A[j]-A[i-1]);
	for(int i=1; i<=N2; ++i) for(int j=i; j<=N2; ++j) 
		seqB.push_back(B[j]-B[i-1]);
	sort(all(seqB));
	ll ans=0;
	for(int i=0; i<sz(seqA); ++i) {
		auto lb=lower_bound(all(seqB), G-seqA[i]);
		auto ub=upper_bound(all(seqB), G-seqA[i]);
		ans+=ub-lb;
	}
	cout << ans << '\n';
}