#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int n, ans=1; cin >> n;
	vector<int> seq(n); for(int i=0; i<n; ++i) cin >> seq[i];
	vector<int> inc(n,1), dec(n,1);
	for(int i=1; i<n; ++i) {
		if(seq[i]>=seq[i-1]) {
			inc[i]=inc[i-1]+1;
			ans=max(ans,inc[i]);
		}
		if(seq[i]<=seq[i-1]){
			dec[i]=dec[i-1]+1;
			ans=max(ans,dec[i]);
		} 
	}
	cout << ans << '\n';
}