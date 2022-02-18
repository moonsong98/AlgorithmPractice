#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int N; cin >> N;
	vector<int> seq(N);
	for(int i=0; i<N; ++i) cin >> seq[i];
	
	int ans=987654321;
	for(int i=0; i<N; ++i) {
		int cnt=0;
		for(int j=1; j<N; ++j) 
			cnt+=j*seq[(i+j+N)%N];
		ans=min(cnt, ans);
	}
	cout << ans << '\n';
}