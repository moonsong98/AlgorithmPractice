#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>

using namespace std;

typedef long long ll;

const ll MIN = -2000000011ll;
const ll MAX = 2000000011ll;

int main(void) {
	int n;
	cin >> n;
	vector<ll> seq(n);
	for(int i=0; i<n; ++i) cin >> seq[i];
	sort(seq.begin(), seq.end());
	int left=0, right=n-1;
	int sum=MAX, ans[2];
	while(left<right) {
		if(seq[left]+seq[right]==0) {
			ans[0]=seq[left];
			ans[1]=seq[right];
			break;
		}
		else if(seq[left]+seq[right]>0) { 
			if(abs(seq[left]+seq[right])<sum) {
				sum=abs(seq[left]+seq[right]);
				ans[0]=seq[left];
				ans[1]=seq[right];
			}
			right--;
		}
		else {
			if(abs(seq[left]+seq[right])<sum) {
				sum=abs(seq[left]+seq[right]);
				ans[0]=seq[left];
				ans[1]=seq[right];
			}
			left++;
			
		}
	}
	cout << ans[0] << ' ' << ans[1] << '\n';
}
/*
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;

ll absol(ll n) {
	return n>0?n : -n;
}

bool calc(int i, int mid, const vector<ll>& seq){
	if(i<=mid) ++mid;
	return absol(seq[mid]+seq[i]) < absol(seq[mid-1]+seq[i]);
}

int main(void) {
	int n;
	cin >> n;
	vector<ll> seq(n+1);
	seq[0]=(ll)-10000*1000*1000+999;
	for(int i=1; i<=n; ++i) cin>>seq[i];
	sort(seq.begin(), seq.end());
	ll minSum=(ll)30000*1000*1000, ans[2]={-1,-1};
	
	for(int i=1; i<=n; ++i) {
		int low=1, high=n-1;
		ll sum=(ll)-30000*1000*1000, cand[2]={-1, -1};
		while(low <= high) {
			int mid=low+(high-low)/2;
			if(calc(i, mid, seq)) {
				cand[0]=seq[i], cand[1]=i<=mid?seq[mid+1]:seq[mid];
				sum = cand[0]+cand[1];
				low=mid +1;
			} else high = mid-1;
		}
		if(absol(sum)<absol(minSum)) {
			minSum=sum;
			ans[0]=cand[0]; ans[1]=cand[1];
		}
	}	
	sort(ans, ans+2);
	for(int i=0; i<2; ++i) cout << ans[i] << ' ';
	cout <<'\n';
}
*/