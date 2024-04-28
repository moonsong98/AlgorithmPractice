#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

ll N, M, cnt=0;
vector<ll> primes;

void solve(int a, ll cur, int num) {
	int si=a+1;
	if(si==N) return;
	for(int i=si; i<N; ++i) {
		ll next=cur*primes[i];
		if(num%2==0) cnt+=M/next;
		else cnt-=M/next;
		solve(i, next, num+1);
	}
}

int main(void) {
	cin >> N >> M;
	for(int i=0; i<N; ++i) {
		ll a; cin >> a;
		primes.push_back(a);
	}
	solve(-1,1,0);
	cout << cnt << '\n';
}