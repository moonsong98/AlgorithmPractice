#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct {
	int t;
	int nameId;
	bool pos;
	int change;
} log;

bool operator < (log &a, log &b) {
	return a.t < b.t;
}

map<string, int> nameToId={{"Bessie",0},{"Elsie",1},{"Mildred",2}};

int main(void) {
	int n; cin >> n;
	vector<log> logs;
	for(int i=0; i<n; ++i) {
		int t;
		string name;
		char pos;
		int change;
		cin >> t >> name >> pos >> change;
		logs.push_back({t, nameToId[name], (pos=='+'), change});
	}
	sort(logs.begin(), logs.end());
	vector<int> totalAmount(3, 7);
	int elMax=0, ans=0;
	for(log l: logs) {
		if(l.pos) totalAmount[l.nameId]+=l.change;
		else totalAmount[l.nameId]-=l.change;
		int maxV=*max_element(totalAmount.begin(), totalAmount.end()), newElMax=0;
		for(int i=0; i<3; ++i) if(totalAmount[i]==maxV) 
			newElMax|=(1<<i);
		if(elMax!=newElMax) {
			elMax=newElMax;
			++ans;
		}
	}
	cout << ans << '\n';
}