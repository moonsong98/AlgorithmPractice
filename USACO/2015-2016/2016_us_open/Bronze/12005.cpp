#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void) {
	int N, K; cin >> N >> K;
	vector<int> seq(N); for(int i=0; i<N; ++i) cin>>seq[i];
	sort(seq.begin(), seq.end());
	int ans=-1;
	for(int i=0; i<N; ++i) {
		for(int j=0; j<N && seq[j]-seq[i]<=K; ++j)
			ans=max(ans,j-i+1);
	}
	cout << ans <<'\n';
}