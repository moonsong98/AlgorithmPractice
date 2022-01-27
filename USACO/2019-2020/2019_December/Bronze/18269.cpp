#include<iostream>
#include<string>
#include<set>

using namespace std;

int main(void) {
	int N; string str; cin >> N >> str;
	set<string> s;
	int ans=-1;
	for(int i=0; i<N; ++i) for(int j=1; j<=N-i; ++j) {
		string sub=str.substr(i, j);
		if(s.find(sub)==s.end())
			s.insert(sub);
		else 
			ans=max(ans, j);
	}
	cout << min(ans+1, N);
}