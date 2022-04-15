#include<bits/stdc++.h>
#define p first
#define q second
#define all(x) x.begin(), x.end()
using namespace std;
typedef pair<int,int> pii;

int main(void){
	cin.tie(nullptr)->sync_with_stdio(false);
	int N, M, R;
	long long ans=0, cur=0;
	cin >> N >> M >> R;
	vector<int> cow(N);
	priority_queue<pii> store;
	vector<long long> farm(R);
	stack<long long> farmLeft;
	for(int i=0; i<N; ++i) {
		int a; cin >> a;
		cow.push_back(-a);
	}
	for(int i=0; i<M; ++i) {
		pii a;
		cin >> a.q >> a.p;
		store.push(a);
	}
	for(int i=0; i<R; ++i) {
		int a; cin >> a;
		farm.push_back(-a);
	}
	sort(all(cow));
	sort(all(farm));
	for(int i=0; i<min(N, R); ++i) {
		farmLeft.push(-farm[i]);
		cur+=(-farm[i]);	
	}
	int i=0;
	for(; i<N-R; ++i) {
		int left=-cow[i];
		while(left>0) {
			pii s=store.top(); store.pop();
			if(s.q>left) {
				cur+=(long long)s.p*left;
				s.q-=left;
				store.push(s);
				left=0;
			}
			else {
				cur+=(long long)s.p*s.q;
				left-=s.q;
				s.q=0;
				if(store.empty()) break;
			}
		}
		if(store.empty()) break;
	}
	ans=cur;
	for(; i<N&&!store.empty(); ++i) {
		cur-=farmLeft.top(); farmLeft.pop();
		int left=-cow[i];
		while(left>0) {
			pii s=store.top(); store.pop();
			if(s.q>left) {
				cur+=(long long)s.p*left;
				s.q-=left;
				store.push(s);
				left=0;
			}
			else {
				cur+=(long long)s.p*s.q;
				left-=s.q;
				s.q=0;
				if(store.empty()) break;
			}
		}
		ans=max(ans, cur);
		if(store.empty()) break;
	}
	cout << ans << '\n';
}