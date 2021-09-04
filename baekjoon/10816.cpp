#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int a, b;
	cin >> a;
	vector<int> seq(a);
	for(int i=0; i<a; ++i) {
		cin >> seq[i];
	}
	sort(seq.begin(), seq.end());
	cin >> b;
	for(int j=0; j<b; ++j) {
		int input;
		cin >> input;
		
		int l=0, h=a-1;
		int ans=-1;
		
		while(l<=h) {
			int m=l+(h-l)/2;
			if(seq[m]>=input) {
				ans=m;
				h=m-1;
			} else l=m+1;
		}
		if(ans==-1 || seq[ans]!=input) {
			cout << 0 << ' ';
			continue;
		}
		
		l=0, h=a-1;
		int ansH=-1;
		while(l<=h) {
			int m=l+(h-l)/2;
			if(seq[m]>input) {
				ansH=m;
				h=m-1;
			} else l=m+1;
		}
		if(ansH==-1) ansH=a;
		cout << ansH-ans << ' ';
	}
	cout << '\n';
}
/*
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	unordered_map<int, int> m;
	int a, b;
	cin >> a;
	for(int i=0; i<a; ++i) {
		int input;
		cin >> input;
		m[input]++;
	}
	cin >> b;
	for(int i=0; i<b; ++i) {
		int input;
		cin >> input;
		cout << m[input] << ' ';
	}
	cout << '\n';
}
*/