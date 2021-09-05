#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
	int n,x;
	cin >> n;
	vector<int> seq(n);
	for(int i=0; i<n; ++i) cin >> seq[i];
	cin >> x;
	
	sort(seq.begin(), seq.end());
	
	int low=0, high=n-1;
	int ans=0;
	while(low<high) {
		if(seq[low]+seq[high]<=x) {
			if(seq[low]+seq[high]==x) ++ans;
			++low;
		} else --high;
	}
	cout << ans << '\n';
}