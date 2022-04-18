#include<bits/stdc++.h>
using namespace std;

const int MOD=32768;
int cache[32768];

void dp(int n) {
	if(cache[(n+MOD-1)%MOD]>cache[n]+1) {
		cache[(n+MOD-1)%MOD]=cache[n]+1;
		dp((n+MOD-1)%MOD);
	}
	if(cache[n/2]>cache[n]+1) {
		cache[n/2]=cache[n]+1;
		dp(n/2);
	}
	if(cache[(n+MOD)/2]>cache[n]+1) {
		cache[(n+MOD)/2]=cache[n]+1;
		dp((n+MOD)/2);
	}
}

int main(void) {
	int N; cin >> N;
	for(int i=1; i<MOD; ++i) cache[i]=15;
	dp(0);
	for(int i=0; i<N; ++i) {
		int a; cin >> a;
		cout << cache[a] << ' ';
	}
}