#include<iostream>
#include<string>

using namespace std;

int main(void) {
	int N, K; cin >> N >> K;
	int cnt=0;
	for(int i=0; i<N; ++i) {
		string str; cin >> str;
		if(str.size()+cnt<=K) {
			if(cnt>0) cout << ' ';
			cout << str;
		}
		else {
			cnt=0;
			cout << '\n' << str;
		}
		cnt+=str.size();
	}
}