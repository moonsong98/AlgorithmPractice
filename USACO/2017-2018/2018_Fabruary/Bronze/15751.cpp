#include<iostream>
#include<cmath>

using namespace std;

int main(void) {
	int a, b, x, y;
	cin >> a >> b >> x >> y;
	cout << min(abs(a-b), min(abs(a-x)+abs(b-y), abs(a-y)+abs(b-x))) << '\n';
}