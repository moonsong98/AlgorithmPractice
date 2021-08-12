#include<iostream>

using namespace std;

bool w[30*500+11]={false,}, dp[30][30*500+11]={false,};
int a[30];

void preCalc(int pos, int n, int weight){
	if(pos>n) return;
	if(dp[pos][weight]) return;
	dp[pos][weight]=true;	
	w[weight]=true;
	preCalc(pos+1, n, weight);
	preCalc(pos+1, n, weight+a[pos]);
	int next=weight-a[pos];
	if(next<0) next*=(-1);
	preCalc(pos+1, n, next);
}

int main(void){
	int n;
	cin>>n;
	for(int i=0; i<n; ++i) cin>>a[i];
	preCalc(0,n,0);
	int t;
	cin>>t;
	while(t--){
		int b;
		cin>>b;
		if(b<=30*500 && w[b]) cout<<"Y ";
		else cout<<"N ";
	}
}
//my code
/*
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int dp1[30][65000];
int dp2[30][15000];

int solution(vector<int>& a, int pos, int b){
	if(pos==a.size()) return b==0;
	int& ret=(b>=0? dp1[pos][b]:dp2[pos][-b]);
	if(ret!=-1) return ret;
	return ret=solution(a, pos+1, b)||solution(a, pos+1,b+a[pos])||solution(a,pos+1,b-a[pos]);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, b;
	cin >> n;
	vector<int> a(n,0);
	int asum=0;
	for(int i=0; i<n; ++i) {
		cin>>a[i];
		asum+=a[i];
	}
	cin>>m;
	for(int i=0; i<m; ++i){
		memset(dp1, -1, sizeof(dp1));
		memset(dp2, -1, sizeof(dp2));
		cin>>b;
		if(b>asum) {
			cout<<"n ";
			continue;
		}
		bool ans=solution(a, 0, b);
		cout<< (ans?"y ":"n ");
	}
}
*/