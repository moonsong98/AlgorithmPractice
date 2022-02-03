#include<iostream>
#include<algorithm>

using namespace std;

typedef struct {
	int s;
	int t;
} cow;

bool operator < (cow& A, cow& B) {
	if(A.s != B.s) return A.s < B.s;
	return A.t < B.t;
}

int main(void) {
	int N; cin >> N;
	cow cows[100];
	for(int i=0; i<N; ++i) cin >> cows[i].s >> cows[i].t;
	sort(cows, cows+N);
	int ans=0;
	for(int i=0; i<N; ++i) {
		if(ans < cows[i].s) ans=cows[i].s+cows[i].t;
		else ans+=cows[i].t;
	}
	cout << ans << '\n';
}