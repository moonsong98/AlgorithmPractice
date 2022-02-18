#include<iostream>
#include<vector>

using namespace std;

const int INF=987654321;

int main(void) {
	int A, B, N; cin >> A >> B >> N;
	int ans=INF;
	for(int i=0; i<N; ++i) {
		int cost, len; cin >> cost >> len;
		int cnt=0;
		for(int j=0; j<len; ++j) {
			int num; cin>>num;
			if(cnt==0 && num==A) ++cnt;
			else if(cnt==1 && num==B) ans=min(ans, cost);
		}
	}
	cout << (ans==INF?-1:ans) << '\n';
}