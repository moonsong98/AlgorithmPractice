#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	set<string> s;
	vector<string> ans;
	int N, M;
	cin >> N >> M;
	for(int i=0; i<N; ++i) {
		string str;
		cin >> str;
		s.insert(str);
	}
	for(int i=0; i<M; ++i) {
		string str;
		cin >> str;
		if(s.count(str)) ans.push_back(str);
	}
	sort(ans.begin(), ans.end());
	cout << (int)ans.size() << '\n';
	for(string s: ans) cout << s << '\n';
}