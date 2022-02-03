#include<iostream>

using namespace std;

int main(void) {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if(a<d && b>c) cout << (max(b,d)-min(a,c)) << '\n';
	else cout << b-a+d-c << '\n';
}