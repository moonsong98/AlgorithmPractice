#include<iostream>

using namespace std;

int main(void) {
	int x, y; cin >> x >> y;
	int mv=1;
	int ans=0;
	int curPos=x+1;
	while (true) {
		if(curPos<y && x+mv>=y) {
			ans+=(y-curPos);
			break;
		}
		curPos=x+mv;
		ans+=(mv+mv/2);
		mv*=2;
		if(curPos>y && x-mv<=y) {
			ans+=(curPos-y);
			break;
		}
		curPos=x-mv;
		ans+=(mv+mv/2);
		mv*=2;
	}
	cout << ans << '\n';
}