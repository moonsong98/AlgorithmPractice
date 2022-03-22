#include<bits/stdc++.h>

using namespace std;

long long M=20090711ll;

typedef struct RNG {
	long long a, b, cur;
	RNG(int _a, int _b):a(_a), b(_b), cur(1983ll) {}
	long long next() {
		long long ret=cur;
		cur=(cur*a+b)%M;
		return ret;
	}
} RNG;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		int n, a, b;
		cin >> n >> a >> b;
		long long ans=0ll;
		priority_queue<int, vector<int>, less<int>> pq_front;
		priority_queue<int, vector<int>, greater<int>> pq_back;
		RNG rng(a, b);
		for(int i=0; i<n; ++i) {
			int cur=rng.next();
			if(pq_front.empty()||cur<=pq_front.top()) pq_front.push(cur);
			else pq_back.push(cur);
			while(pq_front.size()>pq_back.size()+1) {
				pq_back.push(pq_front.top());
				pq_front.pop();
			}
			while(pq_back.size()>pq_front.size()) {
				pq_front.push(pq_back.top());
				pq_back.pop();
			}
			ans+=pq_front.top();
			ans%=M;
		}
		cout << ans << '\n';
	}
}
