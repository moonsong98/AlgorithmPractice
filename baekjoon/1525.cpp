#include<iostream>
#include<map>
#include<queue>

using namespace std;

map<string, int> m;

int dir[4]={-3,-1,1,3};

void swap(char &a, char &b) {
	char c=a;
	a=b;
	b=c;
}

bool inBound(int pos) {
	return 0<=pos && pos<9;
}

void preCalc() {
	string board("123456780");
	queue<string> q;
	q.push(board);
	m[board]=0;	
	while(!q.empty()){
		string qf=q.front();
		int cost=m[qf];
		q.pop();
		int pos=0;
		for(; pos<9; ++pos) if(qf[pos]=='0') break;
			
		for(int i=0; i<4; ++i) {
			int newPos=pos+dir[i];
			if(inBound(newPos)) {
				swap(qf[pos], qf[newPos]);
				if(!m.count(qf)) {
					m[qf]=cost+1;
					q.push(qf);
				}
				swap(qf[pos], qf[newPos]);
			}
		}
	}
}

int main(void) {
	preCalc();
	string str;
	for(int i=0; i<9; ++i) {
		char a;
		cin >> a;
		str+=a;
	}
	cout << (m.count(str)?m[str]:-1) <<'\n';
}