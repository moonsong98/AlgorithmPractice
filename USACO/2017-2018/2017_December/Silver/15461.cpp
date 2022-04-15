#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef pair<int,int> pii;

typedef struct {
	bool sign;
	int diff, time, id;
} Log;

bool operator < (const Log& a, const Log& b) {
	return a.time < b.time;
}

int main(void) {
	int N, G;
	cin >> N >> G;
	vector<Log> Logs;
	for(int i=0; i<N; ++i) {
		Log l;
		char ch;
		cin >> l.time >> l.id >> ch >> l.diff;
		l.sign=ch=='+';
		Logs.push_back(l);
	}
	sort(all(Logs));
	
	map<int,int> leaderboard, curValue;
	leaderboard[G]=2*N;
	int ans=0;
	for(Log l:Logs) {
		if(curValue.count(l.id)==0) curValue[l.id]=G;
		int curAmount=curValue[l.id];
		bool isLargest=leaderboard.rbegin()->first==curAmount;
		int largestNum=leaderboard.rbegin()->second;
		//Erase Current
		leaderboard[curAmount]--;
		if(leaderboard[curAmount]==0) leaderboard.erase(curAmount);
		
		//Add Future
		int futureAmount=curAmount+(l.sign?l.diff:-l.diff);
		leaderboard[futureAmount]++;
		bool isFutureLargest=leaderboard.rbegin()->first==futureAmount;
		int futureLargestNum=leaderboard.rbegin()->second;
		curValue[l.id]=futureAmount;
		
		if(isLargest) {
			if(isFutureLargest && 
			   (largestNum>1&&futureLargestNum==1 
				|| largestNum==1&&futureLargestNum>1)) ++ans; 
			else if(isFutureLargest==false) ++ans;
		}
		else if(isFutureLargest) ++ans;
	}
	cout << ans << '\n';
}