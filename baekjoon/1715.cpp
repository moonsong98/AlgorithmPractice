#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n; priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=0; i<n; ++i) {
		int a; cin >> a;
		pq.push(a);
	}
	long long ans=0;
	while(pq.size()>1) {
		int a=pq.top(); pq.pop();
		int b=pq.top(); pq.pop();
		ans+=a+b;
		pq.push(a+b);
	}
	cout << ans << '\n';
}