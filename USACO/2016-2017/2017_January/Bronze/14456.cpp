#include<iostream>

using namespace std;

int main(void) {
	int n, numA=0, numB=0;
	cin >> n;
	for(int i=0; i<n; ++i) {
		int a, b; cin >> a >> b;
		if(a==b) continue;
		if(a==b-1 || a==b+2) ++numA;
		else ++numB;
	}
	cout << max(numA, numB) << '\n';
}