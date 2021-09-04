#include<iostream>
#include<string>

using namespace std;

int main(void) {
	while(true) {
		string str;
		cin >> str;
		if(str=="0") break;
		bool done=false;
		for(int i=0; i*2<=str.size(); ++i) {
			if(str[i]!=str[str.size()-i-1]) {
				cout << "no" << '\n';
				done=true;
				break;
			}
		}
		if(done) continue;
		cout << "yes" << '\n';
	}
}