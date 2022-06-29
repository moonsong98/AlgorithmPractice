#include<bits/stdc++.h>
using namespace std;

int main(void) {
	int tt; scanf("%d", &tt);
	while(tt--) {
		int n; scanf("%d", &n);
		vector<int> v(n), ans(n);
		vector<pair<int,vector<int>>> m;
		for(int i=0; i<n; ++i) {
			cin >> v[i];
			if(m.empty()||m.back().first!=v[i])
				m.push_back({v[i], vector<int>(1, i+1)});
			else
				m.back().second.push_back(i+1);
		}
		bool valid=true;
		for(auto it: m)
			if(it.second.size()==1)
				valid=false;
		if(!valid) {
			cout << -1 << '\n';
			continue;
		}
		int cnt=0;
		for(int i=0, j=0; i<n; ++i) {
			if(m[j].first!=v[i]) {
				++j;
				cnt=0;
			}
			int sz=m[j].second.size();
			ans[i]=m[j].second[(cnt+1)%sz];
			++cnt;
		}
		for(int i=0; i<n; ++i)
			cout << ans[i] << ' ';
		cout << '\n';
	}
}