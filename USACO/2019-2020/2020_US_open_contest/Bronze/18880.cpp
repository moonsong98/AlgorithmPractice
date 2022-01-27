#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>

using namespace std;

int main(void) {
	int N; string seq; cin >> N >> seq;
	int i=0, ls=0, rs=0, cnt=0;
	priority_queue<int> pq;
	while(seq[i]=='0' && i<N) ++i;
	ls=i;
	for(;i<N; ++i) {
		if(seq[i]=='1'&&cnt) {
			pq.push(cnt+1);
			cnt=0;
		}
		else if(seq[i]=='0') ++cnt;
	}
	if(ls==N) {
		cout << ls-1 << '\n';
		return 0;
	}
	rs=cnt;
	for(i=0; i<2; ++i) {
		int a=pq.empty()?-1:pq.top(), maxDistance;
		maxDistance=max({ls, rs, a-a/2});
		if(maxDistance==ls) {
			ls=0;
			pq.push(maxDistance);
		}
		else if(maxDistance==rs) {
			rs=0;
			pq.push(maxDistance);
		}
		else {
			pq.pop();
			if(a==3) pq.push(2);
			else {
				pq.push(a/2);
				pq.push(a-a/2);
			}
		}
	}
	while(pq.size()>1) pq.pop();
	cout << (pq.empty()?1:pq.top())<< '\n';
}