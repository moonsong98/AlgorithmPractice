#include<iostream>
#include<vector>

using namespace std;

typedef struct {
	string opType;
	int s;
	int e;
} sensor;

int main(void) {
	int n; cin >> n;
	vector<sensor> sensors;
	int curS, curE;
	string curOpType="";
	for(int i=0; i<n; ++i) {
		string opType; int s, e;
		cin >> opType >> s >> e;
		if(curOpType=="" || curOpType!=opType) {
			if(curOpType!="")
				sensors.push_back({curOpType, curS, curE});
			curOpType=opType;
			curS=s; curE=e;
		}
		else {
			if(opType=="on"||opType=="off") {
				curS+=s; curE+=e;
			}
			else {
				curS=max(curS, s); curE=min(curE, e);
			}
		}
	}
	sensors.push_back({curOpType, curS, curE});
	
	int i=sensors.size()-1; while(sensors[i].opType!="none") --i;
	curS=sensors[i].s, curE=sensors[i].e;
	--i;
	for(; i<sensors.size(); --i) {
		int s=sensors[i].s, e=sensors[i].e;
		if(sensors[i].opType=="none") {
			curS=max(curS, s); curE=min(curE, e);
		}
		else if(sensors[i].opType=="on") {
			curS-=e; curE-=s;
		}
		else if(sensors[i].opType=="off") {
			curS+=s; curE+=e;
		}
		curS=max(curS, 0); curE=max(curE, 0);
	}
	cout << curS << ' ' << curE << '\n';
	
	i=0; while(sensors[i].opType!="none") ++i;
	curS=sensors[i].s, curE=sensors[i].e;
	++i;
	for(; i<sensors.size(); ++i) {
		int s=sensors[i].s, e=sensors[i].e;
		if(sensors[i].opType=="none") {
			curS=max(curS, s); curE=min(curE, e);
		}
		else if(sensors[i].opType=="on") {
			curS+=s; curE+=e;
		}
		else if(sensors[i].opType=="off") {
			curS-=e; curE-=s;
		}
		curS=max(curS, 0); curE=max(curE, 0);
	}
	cout << curS << ' ' << curE;
}