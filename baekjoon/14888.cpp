#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;
const ll INF=9876543210, NEGINF=-9876543210;
vector<ll> nums;
vector<int> used, operators;
int numOps;
ll m=INF, M=NEGINF;

void calc() {
	ll ret=nums[0];
	for(int i=0; i<used.size(); ++i){
		if(used[i]==0) ret+=nums[i+1];
		if(used[i]==1) ret-=nums[i+1];
		if(used[i]==2) ret*=nums[i+1];
		if(used[i]==3) ret/=nums[i+1];
	}
	m=min(m,ret);
	M=max(M,ret);	
}

void solve() {
	if(used.size()==numOps) calc();
	for(int i=0; i<4; ++i) {
		if(operators[i]) {
			--operators[i];
			used.push_back(i);
			solve();
			++operators[i];
			used.pop_back();
		}
	}
}

int main(void) {
	int n;
	cin >> n;
	nums=vector<ll>(n);
	operators=vector<int>(4, 0);
	for(int i=0; i<n; ++i) cin >> nums[i];
	for(int i=0; i<4; ++i) {
		cin >> operators[i];
		numOps+=operators[i];
	}
	solve();
	cout << M << '\n' << m << '\n';
}