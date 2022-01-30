#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int n; cin >> n;
	vector<int> seq(n); for(int i=0; i<n; ++i) cin >> seq[i];
	for(int i=n-1; i>0; --i) {
		if(seq[i]<seq[i-1]) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << 0 << '\n';
}