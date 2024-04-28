#include<iostream>
#include<string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	unsigned int M, S=0, x;
	string c;
	cin >> M;
	while(M--) {
		cin >> c;
		if(c=="add") {
			cin >> x;
			S |= (1<<x);
		}
		else if(c=="remove") {
			cin >> x;
			S &= ~(1<<x);
		}
		else if(c=="check") {
			cin >> x;
			cout << ((S&(1<<x)) != 0) << '\n';
		}
		else if(c=="toggle") {
			cin >> x;
			S ^= (1<<x);
		}
		else if(c=="all") {
			S=(1<<21)-1;
		}
		else if(c=="empty") {
			S=0;
		}
	}
}