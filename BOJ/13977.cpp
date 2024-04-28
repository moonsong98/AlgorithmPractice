#include<iostream>

using namespace std;

typedef long long ll;
const ll MOD=1000000007;
ll factorial[4000001];

ll mul(const ll& A, const ll& B) {
	return ((A%MOD)*(B%MOD))%MOD;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	factorial[0]=1;
	for(int i=1; i<=4000000; ++i) factorial[i]=mul(factorial[i-1],i);
	int n, m, k;	
	cin >> m;
	while(m--) {
		cin >> n >> k;
		ll A=1, B=1, ans=1, t=MOD-2;
		A=factorial[n];
		B=mul(factorial[n-k],factorial[k]);
		while(t) {
			if(t&1) ans=mul(ans,B); 
			B=mul(B,B);
			t>>=1;
		}
		ans=mul(ans,A);
		cout << ans << '\n';
	}
}