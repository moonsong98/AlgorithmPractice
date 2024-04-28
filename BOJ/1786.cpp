#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string H, N;
	vector<int> ans;
	getline(cin, H);
	// cin.ignore();
	getline(cin, N);
	vector<int> fail(sz(N), 0);
	for(int i=1, j=0; i<sz(N); ++i) {
		while(j>0&&N[i]!=N[j]) j=fail[j-1];
		if(N[i]==N[j]) fail[i]=++j;
	}
	for(int i=0, j=0; i<sz(H); ++i) {
		while(j>0 && H[i]!=N[j]) j=fail[j-1];
		if(H[i]==N[j]) {
			++j;
			if(j==sz(N)) {
				ans.push_back(i-j+1);
				j=fail[j-1];
			}
		}
	}
	cout << sz(ans) << '\n';
	for(int a: ans) cout << a+1 << ' ';
	cout << '\n';
}