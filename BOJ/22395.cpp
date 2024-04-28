#include<iostream>
#include<stack>
#include<string>

using namespace std;

string words[2] = {"V", "딸기"};

int main(void) {
	int t;
	cin >> t;
	while(t--) {
		int n;
		stack<int> s;
		string ans;
		cin >> n;
		n%=28;
		if(n==0) n=28;
		if(n>15) n=30-n;
		while(n>0) {
			s.push(n%2);
			n/=2;
		}
		for(int i=0; i+s.size() < 4; ++i) ans+=words[0];
		while(!s.empty()){
			ans+=words[s.top()];
			s.pop();
		}
		cout<<ans<<'\n';
	}
}