#include<iostream>

using namespace std;

int main(void) {
	long long x1, x2, y1, y2, r1, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	cout << ((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) <(r1+r2)*(r1+r2) ? "YES" : "NO" ) << '\n';
}