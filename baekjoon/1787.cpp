#include<bits/stdc++.h>
#define sz(x) (long long)x.size()

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n; cin >> n;
	string N; cin >> N;
	vector<long long> fail(n, 0);
	for(long long i=1, j=0; i<n; ++i) {
		while(j>0 && N[i]!=N[j]) j=fail[j-1];
		if(N[i]==N[j]) fail[i]=++j;
	}
	long long ans=0ll;
	for(long long i=1; i<=n; ++i) {
		long long j=fail[i-1];
		while(j>0 && fail[j-1]>0) fail[i-1]=j=fail[j-1];
		if(j>0) ans+=i-j;
	}
	cout << ans <<'\n';
}