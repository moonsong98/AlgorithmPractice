#include<iostream>
#include<algorithm>

using namespace std;

int fences[20001];
int n;

int rectangular(int left, int right) { 
	if(left == right) return fences[left];
	int mid = (left + right)/2;
	int idx1 = mid;
	int idx2 = mid + 1;
	int currentHeight = min(fences[idx1], fences[idx2]);
	int ret = 2*currentHeight;
	ret = max(ret, rectangular(left, idx1));
	ret = max(ret, rectangular(idx2, right));
	while(idx1 >= left && idx2 <= right) {
		if(idx2 < right && (idx1 == left || fences[idx2+1] > fences[idx1 - 1]))
			currentHeight = min(currentHeight, fences[++idx2]);
		else currentHeight = min(currentHeight, fences[--idx1]);
		ret = max(ret, currentHeight*(idx2-idx1+1));
	}
	return ret;
}

void solve() {
	cin >> n;	
	for(int i = 0; i < n; ++i)
		cin >> fences[i];
	
	cout << rectangular(0, n-1) << endl;
}

int main(void) {
	cin.sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) solve();
}