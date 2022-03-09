#include<iostream>
#include<vector>
#include<algorithm>
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;

int main(void) {
	int N, S;
	cin >> N >> S;
	int half=N/2;
	vector<ll> V(N);
	for(ll &v: V) cin >> v;
	vector<ll> fh(1<<(half)), sh(1<<(N-half));
	for(int i=0; i<half; ++i) 
		for(int j=0; j<(1<<half); ++j) 
			if(j&(1<<i)) fh[j]+=V[i];
	for(int i=0; i<N-half; ++i) 
		for(int j=0; j<(1<<(N-half)); ++j) 
			if(j&(1<<i)) sh[j]+=V[i+half];
	sort(all(fh), greater<ll>());
	sort(all(sh));
	int l=0, r=0;
	ll ans=0;
	while(l<(1<<half)&&r<(1<<(N-half))) {
		if(fh[l]+sh[r]==S) {
			int ll=l, rr=r;
			while(ll<(1<<half)&&fh[ll]==fh[l]) ++ll;
			while(rr<(1<<(N-half))&&sh[rr]==sh[r]) ++rr;
			ans+=(long long)(ll-l)*(rr-r);
			r=rr, l=ll;
		}
		else if(fh[l]+sh[r]>S) ++l;
		else ++r;
	}
	cout << (S==0?ans-1:ans) << '\n';
}