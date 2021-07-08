#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

const int MAX = 12345678;

vector<int> switches[10] = {
	{0, 1, 2},
	{3, 7, 9, 11},
	{4, 10, 14, 15},
	{0, 4, 5, 6, 7},
	{6, 7, 8, 10, 12},
	{0, 2, 14, 15},
	{3, 14, 15},
	{4, 5, 7, 14, 15},
	{1, 2, 3, 4, 5},
	{3, 4, 5, 9, 13}
};

bool allSync(int clocks[16]) {
	for(int i = 0; i < 16; ++i)
		if(clocks[i] != 12) return false;
	
	return true;
}

void moveClock(int clocks[16], int switchNum) {
	for(int i = 0; i < switches[switchNum].size(); ++i) {
		int clockNum = switches[switchNum][i];	
		clocks[clockNum] = (clocks[clockNum] == 12 ? 3 : clocks[clockNum] + 3);
	}
}

int sync(int clocks[16], int switchNum, int cnt) {
	if(switchNum == 10)
		return allSync(clocks) ? cnt : MAX;
	
	int ret = MAX;
	
	for(int i = 0; i < 4; ++i) {
		ret = min(ret, sync(clocks, switchNum+1, cnt+i));
		moveClock(clocks, switchNum);
	}
	return ret;	
}

void solve() {
	int clocks[16];
	for(int i = 0 ; i < 16; ++i)
		cin >> clocks[i];
	
	int ans = sync(clocks, 0, 0);
	
	cout << (ans >= MAX ? -1 : ans) << endl; 
}

int main(void) {
	cin.sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) solve();
}