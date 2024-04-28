#include<iostream>
#include<vector>

using namespace std;

int n, s, ans=0;
vector<int> nums;

void find(int e, int sum) {
	int startIndex=e+1;
	if(startIndex==n) return;
	for(int i=startIndex; i<n; ++i) {
		int calcRes=sum+nums[i];
		if(calcRes==s) ++ans;
		find(i, calcRes);
	}
}

int main(void) {
	cin >> n >> s;
	nums=vector<int>(n); for(int i=0; i<n; ++i) cin >> nums[i];
	find(-1, 0);
	cout << ans << '\n';
}