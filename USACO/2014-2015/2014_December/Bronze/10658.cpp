#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

typedef struct {
	int pos;
	bool S;
} cow;

bool operator < (cow &a, cow &b) {
	return a.pos < b.pos;
}

int main(void) {
	int N, A, B;
	cin >> N >> A >> B;
	vector<cow> c(N);
	for(int i=0; i<N; ++i) {
		string str; 
		cin >> str >> c[i].pos;
		c[i].S=(str=="S"?true:false);
	}
	sort(c.begin(), c.end());
	int ans=0, si=0, ei=c.size()-1;
	
	// Out of bound
	if(B<=c[0].pos) {
		cout << (c[0].S?B-A+1:0) << '\n';
		return 0;
	}
	if(A>=c[c.size()-1].pos) {
		cout << (c[c.size()-1].S?B-A+1:0) << '\n';
		return 0;
	}
	
	// Pre-Calculation
	if(A<c[0].pos) {
		if(c[0].S) ans+=(c[0].pos-A);
	}
	else {
		while(si<c.size() && A>=c[si].pos) ++si;
		--si;
		if(c[si].S) {
			if(c[si+1].S) ans -= A-c[si].pos;
			else {
				int mid=c[si].pos+(c[si+1].pos-c[si].pos)/2;
				if(A>mid)
					ans -= mid-c[si].pos+1;
				else 
					ans -= A-c[si].pos;
			}
		}
		else {
			if(c[si+1].S) {
				int mid=c[si].pos+(c[si+1].pos-c[si].pos+1)/2;
				if(A>mid) ans-= A-mid;
			}
		}
	}
	if(B>=c[c.size()-1].pos) {
		if(c[c.size()-1].S) ans+=(B-c[c.size()-1].pos+1);
	}
	else {
		while(ei>=0 && B<c[ei].pos) --ei;
		++ei;
		if(c[ei-1].S) {
			if(c[ei].S) ans -= c[ei].pos-B-1;
			else {
				int mid=c[ei-1].pos+(c[ei].pos-c[ei-1].pos)/2;
				if(B<mid) ans -= mid-B;
			}
		}
		else {
			if(c[ei].S) {
				int mid=c[ei-1].pos+(c[ei].pos-c[ei-1].pos+1)/2;
				if(B<mid) ans -= c[ei].pos-mid;
				else ans -= c[ei].pos-B-1;
			}
		}
	}
	for(int i=si; i<ei; ++i) {
		if(c[i].S) {
			if(c[i+1].S) ans+=c[i+1].pos-c[i].pos;
			else ans+=(c[i+1].pos-c[i].pos)/2+1;
		}
		else {
			if(c[i+1].S) ans += c[i+1].pos-c[i].pos-(c[i+1].pos-c[i].pos+1)/2;
		}
	}
	cout << ans << '\n';
}