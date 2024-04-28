#include<iostream>
#include<vector>

using namespace std;

int n, m;

void solution(vector<int>& chosen) {
	if(chosen.size()==m) {
		for(int a: chosen) cout << a << ' ';
		cout << '\n';
		return;
	}
	for(int i=1; i<=n; ++i) {
		chosen.push_back(i);
		solution(chosen);
		chosen.pop_back();
	}
}

int main(void) {
	cin >> n >> m;
	vector<int> chosen;
	solution(chosen);
}