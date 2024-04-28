#include<bits/stdc++.h>
using namespace std;

int sqr(int n) {return n*n;};

int dq(int lb, int ub, int n, int r, int c) {
	if(n==0) return lb;
	int half=1<<(n-1);
	int nextSize=sqr(1<<(n-1));
	if(r<half)
		if(c<half)
			return dq(lb, lb+nextSize-1, n-1, r, c);
		else 
			return dq(lb+nextSize, lb+nextSize*2-1, n-1, r, c-half);
			
	else
		if(c<half)
			return dq(lb+nextSize*2, lb+nextSize*3-1, n-1, r-half, c);
		else 
			return dq(lb+nextSize*3, ub, n-1, r-half, c-half);
}

int main(void) {
	int n, r, c;
	cin >> n >> r >> c;
	cout << dq(0, sqr(1<<n)-1, n, r, c) << '\n';
}