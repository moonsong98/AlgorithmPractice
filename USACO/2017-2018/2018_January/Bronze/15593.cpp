#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;
typedef pair<int,int> pii;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	vector<pii> list;
	int n; cin >> n;
	for(int i=0; i<n; ++i) {
		int t1, t2; cin >> t1 >> t2;
		list.push_back({t1, t2});
	}
	sort(list.begin(), list.end());
	
	int curTopIndex=0;
	int ll=list[0].first, rr=list[0].second, lll=list[0].first, rrr=list[0].second;
	int lengthSum=0;
	vector<int> alone(n);
	
	for(int i=1; i<n; ++i) {
		int l=list[i].first, r=list[i].second;
		if(rr<r) {
			if(rr<l) {
				alone[curTopIndex]+=rr-ll;
				ll=l;
			} 
			else {
				if(l>ll) alone[curTopIndex]+=(l-ll);
				ll=rr;
			}
			rr=r;
			curTopIndex=i;
		}
		else {
			if(l>ll) alone[curTopIndex]+=(l-ll);
			ll=r;
		}
		if(rrr<l) {
			lengthSum+=(rrr-lll);
			lll=l; rrr=r;
		}
		else if(r>rrr) rrr=r;
	}
	lengthSum+=(rrr-lll);
	alone[curTopIndex]+=(rr-ll);
	cout << lengthSum - *min_element(alone.begin(), alone.end()) << '\n';
}