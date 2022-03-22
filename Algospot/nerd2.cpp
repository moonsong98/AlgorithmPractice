#include<bits/stdc++.h>
#define sz(x) (long long)x.size()

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t;
	cin >> t;
	map<int,int> m;
	while(t--) {
		int N;
		long long ans=0ll;
		cin >> N;
		for(int i=0; i<N; ++i) {
			int p, q;
			cin >> p >> q;
			if(!m.empty()){
				auto it=m.lower_bound(p);
				if(it!=m.end() && it->second>q) {
					ans+=sz(m);
					continue;
				}
				if(it!=m.begin()) {
					--it;
					while(true){
						if(it->second>q) break;
						else if(it==m.begin()) {
							m.erase(it);
							break;
						}
						else if(it->second<q){
							auto tmp=it;
							--it;
							m.erase(tmp);
						}
					}
				}
			}
			m[p]=q;
			ans+=sz(m);
		}
		cout << ans << '\n';
		m.clear();
	}
}