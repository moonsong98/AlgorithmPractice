#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<stack>

using namespace std;

int aP[3*1000*100+11];
int aT[3*1000*100+11];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	cin>>q;
	while(q--){
		int n, k;
		vector<pair<int, int>> a;
		cin>>n>>k;
		for(int i=0; i<k; ++i) cin>>aP[i];
		for(int i=0; i<k; ++i) cin>>aT[i];
		for(int i=0; i<k; ++i) a.push_back({aP[i], aT[i]});
		sort(a.begin(), a.end());
		
		stack<int> validA;
		validA.push(0);
		for(int i=1; i<k; ++i){
			if(a[i].first-a[validA.top()].first<a[i].second-a[validA.top()].second) continue;
			while(!validA.empty()){
				if(a[i].first-a[validA.top()].first>=a[validA.top()].second-a[i].second) break;
				validA.pop();
			}
			validA.push(i);
		}
		
		
		vector<int> valid;
		while(!validA.empty()){
			valid.push_back(validA.top());
			validA.pop();
		}
		reverse(valid.begin(), valid.end());
		int prev=valid[0];
		for(int i=1; i<=a[prev].first; ++i)
			cout << a[prev].second + a[prev].first - i <<' ';
		for(int i=1; i<valid.size(); ++i){
			int next=valid[i];
			int pos=(a[next].second-a[prev].second+a[next].first+a[prev].first)/2;
			for(int i=a[prev].first+1; i<=pos; ++i) cout << a[prev].second+i-a[prev].first<<' ';
			for(int i=pos+1; i<=a[next].first; ++i) cout << a[next].second+a[next].first-i<<' ';
			prev=next;
			
		}
		for(int i=a[prev].first+1; i<=n; ++i)
			cout<<a[prev].second+i-a[prev].first <<' ';
		cout << '\n';
	}
}