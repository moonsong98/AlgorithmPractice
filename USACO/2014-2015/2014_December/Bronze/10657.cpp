#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int N; cin >> N;
	vector<int> s;
	int minV=1987654231;
	int ans=0;
	for(int i=0; i<N; ++i) {
		int a, b; cin >> a >> b;
		s.push_back(b);
	}	
	for(int i=s.size()-1; i>=0; --i) {
		if(s[i]<=minV) {
			++ans;
			minV=s[i];
		}
	}
	cout << ans << '\n';
}