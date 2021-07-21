#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

string pattern;
string str;
int cache[101][101];

bool wildcard(int y, int x) {
	//basecase
	if(pattern.size() == y) 
		return str.size() == x;
	if(str.size() == x) {
		// * for 0 character
		if(pattern[y] == '*') return wildcard(y+1,x);
		return false;
	}
	int& ret = cache[y][x];
	if(ret != -1) return ret;
	if(pattern[y] == '?' || pattern[y] == str[x]) return ret = wildcard(y+1,x+1);
	// 0 or 1 character
	if(pattern[y] == '*') 
		return ret = wildcard(y+1, x) | wildcard(y, x+1);
	return false;
}

void solve() {
	cin >> pattern;
	int n;
	cin >> n;
	vector<string> ans;
	while(n--) {
		cin >> str;
		memset(cache,-1,sizeof(cache));
		if(wildcard(0,0)) ans.push_back(str);
	}
	sort(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); ++i)
		cout << ans[i] << endl;
}

int main(void) {
	cin.sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) solve();
}