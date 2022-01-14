#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		priority_queue<long long, vector<long long>, greater<long long> > pq;
		int n; cin >> n;
		long long ans=0; 
		for(int i=0; i<n; ++i) {
			long long a; cin >> a;
			pq.push(a);
		}
		while(pq.size()>1) {
			long long a=pq.top(); pq.pop();
			long long b=pq.top(); pq.pop();
			ans+=a+b;
			pq.push(a+b);
		}
		cout << ans << '\n';
	}
}