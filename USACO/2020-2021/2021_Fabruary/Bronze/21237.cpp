#include<iostream>
#include<string>

using namespace std;

int getAngle(char ch) {
	if(ch=='N') return 0;
	if(ch=='E') return 90;
	if(ch=='S') return 180;
	if(ch=='W') return 270;
}

int main(void) {
	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		int angleDiff=0;
		for(int i=0; i<s.size(); ++i) {
			int a=getAngle(s[i]), b=getAngle(s[(i+1)%s.size()]);
			if(a==b) continue;
			if((a+270)%360==b) angleDiff-=90;
			if((a+90)%360==b) angleDiff+=90;
		}
		cout << (angleDiff==360?"CW":"CCW") << '\n';
	}
}