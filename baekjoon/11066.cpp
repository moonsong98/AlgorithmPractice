#include<iostream>
#include<limits>

using namespace std;

const long long MAX = numeric_limits<long long>::max();
int files[501];
int pSum[501];
long long cache[501][501];

void preSum(int n) {
	pSum[0] = files[0];
	for(int i = 1; i < n; ++i) pSum[i] = pSum[i-1] + files[i];
}

long long merge(int left, int right) {
	long long& ret = cache[left][right];
	if(ret!=-1) return ret;
	
	if(left == right) return ret = 0;
	if(left == right - 1) return ret = files[left] + files[right];
	
	
	ret = MAX;
	int fileSum = pSum[right] - (left == 0 ? 0 : pSum[left-1]);
	for(int k = left; k < right; ++k)
		ret = min(ret, merge(left, k) + merge(k+1, right)+fileSum);
	
	return ret;
}

void solve() {
	int k;
	cin >> k;
	for(int i = 0; i < k; ++i) cin >> files[i];
	preSum(k);
	for(int i = 0; i < k; ++i)
		for(int j = 0; j < k; ++j)
			cache[i][j] = -1;
	cout << merge(0, k-1) << endl;
}

int main(void) {
	cin.sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) solve();
}