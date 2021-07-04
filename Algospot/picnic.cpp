#include<iostream>
#include<cstring>

using namespace std;

int n;
bool areFriends[10][10];

int countPairings(bool taken[10]) {
	int nextKid = -1;
	for(int i = 0; i < n; ++i)
		if(!taken[i]) {
			nextKid = i;
			break;	
		}

	if(nextKid == -1) return 1;
	
	int ret = 0;
	for(int partner = nextKid + 1; partner < n; ++partner)
		if(!taken[partner] && areFriends[nextKid][partner]) {
			taken[nextKid] = taken[partner] = true;
			ret += countPairings(taken);	
			taken[nextKid] = taken[partner] = false;
		}
	
	return ret;
}

void solve() {
	int m;
	bool taken[10];
	
	cin >> n >> m;

	memset(areFriends, false, sizeof(areFriends));
	memset(taken, false, sizeof(taken));
	
	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		a < b ? areFriends[a][b] = true : areFriends[b][a] = true;
	}
	
	
	cout << countPairings(taken) << endl;	
}

int main(void) {
	cin.sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) solve();
}