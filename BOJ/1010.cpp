#include<iostream>

using namespace std;

long long cache[31][31];

long long bridge(int left, int right) {
	long long& ret = cache[left][right];
	if(ret != -1) return ret;
	if(left == 1) return ret = right;
	
	ret = 0;
	for(int i = right - 1; i >= left - 1; --i)
		ret += bridge(left-1, i);
	
	return ret;
}

void solve() {
	int N, M;	
	cin >> N >> M;
	cout << bridge(N, M) << endl;
}

int main(void) {
	for(int i = 0; i < 30; ++i)
		for(int j = 0; j < 30; ++j)
			cache[i][j] = -1;
	int t;
	cin >> t;
	while(t--) solve();
}