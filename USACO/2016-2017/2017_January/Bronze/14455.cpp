#include<iostream>
#include<string>
#include<map>

using namespace std;

const int MAX=987654321;

int main(void) {
	int n; cin >> n;
	int cntCows=1;
	map<string, int> m2c;
	for(int i=0; i<n; ++i) {
		string A;
		int milk;
		cin >> A >> milk;
		m2c[A]+=milk;
	}
	int m=MAX, mm=MAX;
	for(auto it=m2c.begin(); it!=m2c.end(); ++it) 
		m=min(m, (*it).second);
	if(m2c.size()<7) m=0;
	for(auto it=m2c.begin(); it!=m2c.end(); ++it) {
		if((*it).second==m) continue;
		mm=min(mm, (*it).second);
	}
	int cnt=0;
	string ans;
	for(auto it=m2c.begin(); it!=m2c.end(); ++it) 
		if((*it).second==mm){
			++cnt;
			ans=(*it).first;
		}
	cout << (cnt==1?ans:"Tie") << '\n';
}
