#include<iostream>
#include<queue>

using namespace std;

typedef struct {
	long long cur=1983ll, M=1ll<<32;
	long long next() {
		long long ret=cur;
		cur=(cur*214013+2531011)%M;
		return ret%10000+1;
	}
} RNG;

int main(void) {
	int T;
	cin >> T;
	while(T--) {
		int K, N;
		cin >> K >> N;
		queue<long long> q;
		long long curSum=0;
		RNG rng;
		int ans=0;
		for(int i=0; i<N; ++i) {
			long long a=rng.next();
			q.push(a);
			curSum+=a;
			while(curSum>K) {
				curSum-=q.front();
				q.pop();
			}
			if(curSum==K) ++ans;
		}
		cout << ans << '\n';
	}
}