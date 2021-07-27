#include<iostream>

using namespace std;

int main(void) {
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		switch(a%3) {
			case 0:
				cout << a / 3 << " " << a / 3 << endl;
				break;
			case 1:
				cout << a / 3 + 1 <<  " " << a / 3 << endl;
				break;
			case 2:
				cout << a / 3 << " " << a / 3 + 1 << endl;
				break;
		}
	}
}