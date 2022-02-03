#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
	int n; cin >> n;
	vector<int> seq(n); for(int i=0; i<n; ++i) cin >> seq[i];	
	vector<int> sortedSeq; sortedSeq.assign(seq.begin(), seq.end()); sort(sortedSeq.begin(), sortedSeq.end());
	int ans=0;
	for(int i=0; i<n; ++i) 
		if(seq[i]!=sortedSeq[i])
			++ans;
	cout << ans << '\n';
}
