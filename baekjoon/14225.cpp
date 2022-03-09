#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<int> num;
set<int> s;
int n;

void solve(int e, int sum) {
	int si=e+1;
	if(si==n) return;
	for(int i=si; i<n; ++i) {
		int calcRes=sum+num[i];
		s.insert(calcRes);
		solve(i, calcRes);
	}
}

int main(void) {
	cin >> n;
	num=vector<int>(n);
	for(int& i: num) cin >> i;
	solve(-1, 0);
	int min=0;
	for(auto it=s.begin(); it!=s.end(); ++it) {
		int el=*it;
		if(el==min+1) min=el;
		else {
			cout << min+1 << '\n';
			return 0;
		}
	}
	cout << min+1 << '\n';
}
