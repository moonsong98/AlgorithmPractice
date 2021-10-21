#include<iostream>

using namespace std;

int main(void) {
	int a, b, h, m;
	cin >> a >> b >> m;
	h=m/60;
	m%=60;
	a+=h;
	b+=m;
	if(b>=60){
		a+=b/60;
		b%=60;
	}
	a%=24;
	cout << a << ' ' << b << '\n';
}