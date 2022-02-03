#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void) {
	int N, M; cin >> N >> M;
	vector<string> seq(2*N);
	vector<int> nums1(M, 0), nums2(M, 0);
	for(int i=0; i<2*N; ++i) cin >> seq[i];
	for(int i=0; i<M; ++i) {
		for(int j=0; j<N; ++j)
			nums1[i] |= 1 << (seq[j][i]-'A');
		for(int j=0; j<N; ++j)
			nums2[i] |= 1 << (seq[j+N][i]-'A');
	}
	int ans=0;
	for(int i=0; i<M; ++i) ans+=((nums1[i]&nums2[i])==0);
	cout << ans << '\n';
}