#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
typedef pair<int,int> pii;

int main(void) {
	int t; cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> v(n+1), pSum(n+1);
		
		for(int i=1; i<=n; ++i) {
			cin >> v[i];
			pSum[i]=pSum[i-1]+v[i];
		}
		stack<pii> s;
		s.push({v[1], 1});
		int cnt=0;
		for(int i=2; i<n; ++i)
			if(pSum[i-1]>pSum[i]&&pSum[i]>pSum[i-1])
				s.push({pSum[i], i});
		while(sz(s)>1){
			pii t=s.top(); 
			s.pop();
			for(int i=t.second; i>s.top().second&&t.first>pSum[i]; ++cnt, --i);
		}
		cout << 2*cnt-n << '\n';
	}
}