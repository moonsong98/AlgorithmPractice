#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		int n, m, k;
		cin >> n >> m >> k;
		priority_queue<char, vector<char>, greater<char>> A, B;
		string ans;
		for(int i=0; i<n; ++i) {
			char ch;
			cin >> ch;
			A.push(ch);
		}
		for(int i=0; i<m; ++i) {
			char ch;
			cin >> ch;
			B.push(ch);
		}
		int cnt=0, who=-1;
		while(!A.empty()&&!B.empty()) {
			if(cnt==k) {
				if(who==0) {
					ans.push_back(B.top());
					B.pop();
					who=1;
				}
				else {
					ans.push_back(A.top());
					A.pop();
					who=0;
				}
				cnt=1;
			}
			else {
				if(A.top()<B.top()) {
					ans.push_back(A.top());
					A.pop();
					if(who==0) ++cnt;
					else {
						who=0;
						cnt=1;
					}
				}
				else {
					ans.push_back(B.top());
					B.pop();
					if(who==1) ++cnt;
					else {
						who=1;
						cnt=1;
					}
				}
			}
		}
		cout << ans << '\n';
	}
}