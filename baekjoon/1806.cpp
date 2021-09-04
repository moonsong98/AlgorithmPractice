#include<iostream>
#include<vector>

using namespace std;

int n, s;

int main(void) {
	cin >> n >> s;
	vector<int> seq(n);
	for(int i=0; i<n; ++i) cin >> seq[i];
	int left=1, right=1;
	int ans=987654321;
	int sum=0;
	while(left<=right && right <= n) {
		if(sum<s) sum+=seq[right++];
		if(sum>=s) {
			ans=min(ans,right-left);
			sum-=seq[left++];
		}
	}
	if(ans==987654321) ans=0;
	cout << ans << '\n';
}