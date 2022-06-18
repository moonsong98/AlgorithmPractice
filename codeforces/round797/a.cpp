#include<bits/stdc++.h>
using namespace std;

int main(void) {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n; 
		if(n%3==0)
			cout << n/3 << ' ' << n/3+1 << ' ' << n/3-1 << '\n';
		if(n%3==1)
			cout << n/3 << ' ' << n/3+2 << ' ' << n/3-1 << '\n';
		if(n%3==2)
			cout << n/3+1 << ' ' << n/3+2 << ' ' << n/3-1 << '\n';
	}
}