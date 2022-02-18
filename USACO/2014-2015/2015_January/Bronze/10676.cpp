#include<iostream>
#include<vector>

using namespace std;

const int INF=987654321;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int A, B, N; cin >> A >> B >> N;
	int ans=INF;
	int costA[10001], costB[10001]; for(int i=0; i<=10000; ++i) costA[i]=costB[i]=INF;
	vector<int> seq;
	for(int i=0; i<N; ++i) {
		seq.clear();
		bool isSingle=false;
		int cost, len; cin >> cost >> len;
		int posA=-1, posB=-1;
		int cnt=0;
		for(int j=0; j<len; ++j) {
			int num; cin >> num; 
			seq.push_back(num);
			if(num==A) {
				posA=j;
				if(cnt==0) ++cnt;
			}
			else if(num==B) {
				posB=j;
				if(cnt==1) {
					ans=min(ans, cost);
					isSingle=true;
				}
			}
		}
		if(isSingle) continue;
		for(int j=0; j<posB; ++j)
			costB[seq[j]]=min(costB[seq[j]], cost);
		for(int j=posA+1; j<len&&posA!=-1; ++j)
			costA[seq[j]]=min(costA[seq[j]], cost);
	}
	for(int i=1; i<=10000; ++i) ans=min(ans, costA[i]+costB[i]);
	cout << (ans==INF?-1:ans) << '\n';
}