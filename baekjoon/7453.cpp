#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void) {
	int N; cin >> N;
	long long ans=0;
	vector<vector<int>> in(N, vector<int>(4));
	for(int i=0; i<N; ++i)
		cin >> in[i][0] >> in[i][1] >> in[i][2] >> in[i][3];
	vector<int> A;
	vector<int> B;
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) {
		A.push_back(in[i][0]+in[j][1]);
		B.push_back(in[i][2]+in[j][3]);
	}
	sort(A.begin(), A.end(), greater<int>());
	sort(B.begin(), B.end());
	int l=0, r=0;
	while(l<N*N && r<N*N) {
		if(A[l]+B[r]==0) {	
			int ll=l, rr=r;
			while(ll<N*N && A[l]==A[ll]) ++ll;
			while(rr<N*N && B[r]==B[rr]) ++rr;
			ans+=(long long)(ll-l)*(rr-r);
			l=ll; r=rr;
		}
		else if(A[l]+B[r]>0) ++l;
		else if(A[l]+B[r]<0) ++r;
	}
	cout << ans << '\n';
}

/* Binary Search
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int INF=1e9+7;

int main(void) {
	int N; cin >> N;
	long long ans=0;
	vector<vector<int>> in(N, vector<int>(4));
	for(int i=0; i<N; ++i)
		cin >> in[i][0] >> in[i][1] >> in[i][2] >> in[i][3];
	vector<int> A;
	vector<int> B;
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) {
		A.push_back(in[i][0]+in[j][1]);
		B.push_back(in[i][2]+in[j][3]);
	}
	sort(B.begin(), B.end());
	for(int i=0; i<N*N; ++i) {
		int lb=-1, ub=-1;
		int l=0, r=N*N-1;
		while(l<=r) {
			int mid=l+(r-l)/2;
			if(B[mid]+A[i]>=0) {
				lb=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		if(lb==-1 || A[i]+B[lb]!=0) continue; 
		l=0; r=N*N-1;
		while(l<=r) {
			int mid=l+(r-l)/2;
			if(B[mid]+A[i]<=0) {
				ub=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		ans+=ub-lb+1;
	}
	cout << ans << '\n';
}
*/
