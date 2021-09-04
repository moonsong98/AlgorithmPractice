#include<iostream>
#include<stack>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	stack<int> s;
	while(n--){
		int a;
		cin >> a;
		if(a>0) s.push(a);
		else s.pop();
	}
	int ans=0;
	while(!s.empty()){
		ans+=s.top();
		s.pop();
	}
	cout << ans << '\n';
}