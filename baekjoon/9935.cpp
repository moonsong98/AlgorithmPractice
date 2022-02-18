#include<iostream>
#include<string>

using namespace std;

int main(void) {
	string S, T;
	cin >> S >> T;
	string ans="";
	for(char s: S) {
		ans.push_back(s);
		if(s==T.back() && ans.size()>=T.size()){
			bool same=true;
			for(int i=0; i<T.size(); ++i) {
				if(T[T.size()-i-1]!=ans[ans.size()-i-1]) {
					same=false;
					break;
				}
			}
			if(same) for(int i=0; i<T.size(); ++i) ans.pop_back();
		}
	}
	cout << (ans.size()>0?ans:"FRULA") << '\n';
}