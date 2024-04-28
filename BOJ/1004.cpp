#include<iostream>

using namespace std;

int sqrt(int a) {
	return a*a;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while(t--) {
		int x1, y1, x2, y2, n, ans=0;
		cin >> x1 >> y1 >> x2 >> y2 >> n;
		while(n--) {
			int x, y, r;
			cin >> x >> y >> r;
			if(sqrt(x1-x)+sqrt(y1-y) < sqrt(r)) ans+=(sqrt(x2-x)+sqrt(y2-y)>sqrt(r));
			else ans+=(sqrt(x2-x)+sqrt(y2-y)<sqrt(r));
		}
		cout << ans << '\n';
	}
}