#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
	int n, a;
	vector<int> vec;
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a;
		vec.push_back(a);
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());	
	for(int v: vec) cout << v << ' ';
}