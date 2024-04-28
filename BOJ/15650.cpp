#include<iostream>
#include<vector>

using namespace std;

int n, m;

void solution(vector<int>& chosen, vector<int>& isUsed) {
	if(chosen.size()==m) {
		for(int a: chosen) cout << a << ' ';
		cout << '\n';
	}
	for(int i=1; i<=n; ++i) {
		if(chosen.empty() || !isUsed[i] && chosen.back() < i) {
			isUsed[i]=true;
			chosen.push_back(i);
			solution(chosen, isUsed);
			chosen.pop_back();
			isUsed[i]=false;
		}
	}
}

int main(void) {
	cin >> n >> m;
	vector<int> chosen, isUsed(n+1, 0);
	solution(chosen, isUsed);
}