#include<iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	while(n--) {
		long double a, b;
		cin >> a >> b;
		cout << (long double)a*b << '\n';
	}
}