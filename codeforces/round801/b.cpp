#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int winner, pnt=1e10;
		for(int i=0; i<n; ++i) {
			int num; cin >> num;
			if(pnt>num) {
				pnt=num;
				winner=(i+1)%2;
			}
		}
		if(n%2||winner==0) 
			cout << "Mike" << '\n';
		else
			cout << "Joe" << '\n';
	}
}
