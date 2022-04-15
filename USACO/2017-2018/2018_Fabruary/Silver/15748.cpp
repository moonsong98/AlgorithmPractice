#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int L, N, s1, s2;
	cin >> L >> N >> s1 >> s2;
	stack<pii> tmp, s;
	for(int i=0; i<N; ++i) {
		int x, y;
		cin >> x >> y;
		while(!tmp.empty()&&tmp.top().se<=y) tmp.pop();
		tmp.push({x, y});
	}
	while(!tmp.empty()) {
		s.push(tmp.top());
		tmp.pop();
	}
	int curPos=0;
	long long ans=0;
	while(!s.empty()) {
		pii p=s.top(); s.pop();
		ans+=(long long)(p.fi-curPos)*p.se*(s1-s2);
		curPos=p.fi;
	}
	cout << ans << '\n';
}