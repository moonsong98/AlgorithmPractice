#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> v(n);
		for(int i=0; i<n; ++i) cin >> v[i];
		if(n%2) {
			cout << "Mike" << '\n';
			continue;
		}
		int winner=-1;
		int losePnt=-1;
		for(int i=0; i<n/2; ++i) {
			if(v[i*2]<=v[i*2+1] && (losePnt==-1 || v[i*2]<losePnt)) {
				winner=1;
				losePnt=v[i*2];
			}
			else if(v[i*2]>v[i*2+1] && (losePnt==-1 || v[i*2+1]<losePnt)) {
				winner=0;
				losePnt=v[i*2+1];
			}
		}
		cout << (winner?"Joe":"Mike") << '\n';
	}
}