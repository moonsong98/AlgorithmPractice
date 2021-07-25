#include<iostream>
#include<map>

using namespace std;
	
void solve() {
	int ans = 0;
	int numPeople;
	map<int, int> participants;
	
	cin >> numPeople;
	
	for(int i = 0; i < numPeople; ++i) {
		int p, q;
		cin >> p >> q;
		map<int, int>::iterator itlow;
		itlow = participants.lower_bound(p);
		if(itlow == participants.end() || itlow -> second < q)
			participants[p] = q;
		else {
			ans += participants.size();
			continue;
		}
		
		itlow = participants.lower_bound(p);
		if(itlow == participants.begin()) {
			ans += participants.size();
			continue;
		}
		itlow--;
		while(itlow->second < q) {
			if(itlow == participants.begin()) {
				participants.erase(itlow);
				break;
			}
			else {
				itlow = participants.erase(itlow);
				--itlow;
			}
		}
		ans += participants.size();
	}
	cout << ans << endl;
}

int main(void) {
	cin.sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) solve();
}