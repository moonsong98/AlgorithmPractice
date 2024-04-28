#include<iostream>
#include<vector>

using namespace std;

vector<int> b;
int M, N;

int main(void) {
	int l=1, r=1, ans=-1;
	cin >> N;
	for(int i=0; i<N; ++i) {
		int a; cin >> a;
		r=max(r, a);
		b.push_back(a);
	}
	cin >> M;
	while(l<=r) {
		int mid=l+(r-l)/2;
		int total=0;
		for(int i=0; i<N; ++i) {
			total+=min(mid, b[i]);
		}
		if(total<=M) {
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout << ans << '\n';
}