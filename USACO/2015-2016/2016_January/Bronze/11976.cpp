#include<iostream>

using namespace std;

int main(void) {
	int a, b; cin >> a >> b;	
	int d[3];
	for(int i=0; i<3; ++i) {
		int a, b; cin >> a >> b;	
		d[i]=b-a;
	}
	cout << d[0]+d[1]+d[2] << '\n' << d[1]+d[2] << '\n' << d[2] << '\n';
}