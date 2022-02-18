#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int INF=1e9+7;

int main(void) {
	int N, tM;
	cin >> N >> tM;
	vector<int> D(N);
	for(int& d: D) cin >> d;
	int l=1, r=N, ans=INF;
	priority_queue<int> pq;
	while(l<=r) {
		int mid=l+(r-l)/2;
		int t=0;
		for(int i=0; i<N; ++i) {
			if(i<mid) pq.push(-D[i]);
			else {
				pq.push(pq.top()-D[i]);
				pq.pop();
			}
		}
		while(pq.size()>1) pq.pop();
		if(-pq.top()<=tM) {
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
		pq.pop();
	}
	cout << ans << '\n';
}