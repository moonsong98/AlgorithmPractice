#include<iostream>
#include<cstring>

using namespace std;

int colors[200001];

int main(void) {
	cin.sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		memset(colors, 0, sizeof(colors));
		for(int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			if(colors[a] == k) cout << 0 << " ";
			else {
				colors[a] += 1;
				cout << colors[a] << " ";
			}
		}
		cout << endl;
	}
}