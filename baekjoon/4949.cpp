#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(void) {
	bool isFinsihed=false;
	stack<char> s=stack<char>();
	bool ans=true;
	while(true) {
		string str;
		getline(cin, str);
		if(str[0]=='\0') continue;
		if(str.size()==1) break;
		for(int i=0; i<str.size(); ++i) {
			char c=str[i];
			if(c=='.') isFinsihed=true;
			if(!ans) continue;
			if(c=='(' || c=='[') s.push(c);
			if(c==')') {
				if(!s.empty() && s.top()=='(') s.pop();
				else ans=false;
			}
			if(c==']') {
				if(!s.empty() && s.top()=='[') s.pop();
				else ans=false;
			}
		}
		if(isFinsihed) {
			cout << (ans?"yes":"no") << '\n';
			isFinsihed=true;
			s=stack<char>;
			ans=true;
		}
	}
}