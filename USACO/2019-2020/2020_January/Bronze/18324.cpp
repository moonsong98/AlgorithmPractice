#include<iostream>

using namespace std;

int K;

int solve(int n) {
	int d=0, s=0, cnt=0;
	for(s=1; s<=n && d<K; ++s, ++cnt) {
		d+=s;
	}
	--s;
	if(d>=K) return cnt;
	while(d<K) {
		d+=(s++);
		++cnt;
		if(d>=K) break;
		d+=s;
		++cnt;
		if(d>=K) break;
	}
	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N; cin >> K >> N;
	for(int i=0; i<N; ++i) {
		int n; cin >> n;
		cout << solve(n) << '\n';
	}
}