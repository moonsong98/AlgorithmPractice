#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	for(int i=1; i<=t; ++i) {
		int r, c;
		cin >> r >> c;
		cout << "Case #" << i << ":\n";
		
		cout <<"..";
		for(int i=1; i<c; ++i) cout << "+-";
		cout << "+\n";
		cout <<"..";
		for(int i=1; i<c; ++i) cout << "|.";
		cout << "|\n";
		
		for(int i=0; i<c; ++i) cout << "+-";
		cout << "+\n";
		for(int i=1; i<r; ++i) {
			for(int i=0; i<c; ++i) cout << "|.";
			cout << "|\n";
			for(int i=0; i<c; ++i) cout << "+-";
			cout << "+\n";
		}
	}
}