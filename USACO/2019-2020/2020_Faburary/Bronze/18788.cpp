#include<iostream>
#include<vector>

using namespace std;

int N, K;

vector<vector<int>> matMul(vector<vector<int>> A, vector<vector<int>> B) {
	vector<vector<int>> C(N, vector<int>(N,0));
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) for(int k=0; k<N; ++k) 
		C[i][j]+= A[i][k]*B[k][j];
	return C;
}

vector<vector<int>> power(vector<vector<int>> &C, int k) {
	if(k==1) return C;
	else if(k%2) return matMul(power(C,k-1), power(C,1));
	vector<vector<int>> D = power(C, k/2);
	return matMul(D, D);
}

int main(void) {
	cin >> N >> K;	
	vector<vector<int>> I(N,vector<int>(N,0)); for(int i=0; i<N; ++i) I[i][i]=1;
	int a, b;
	vector<vector<int>> A(N,vector<int>(N,0)); cin >> a >> b;
	for(int i=0; i<N; ++i) {
		if(a-1<=i&&i<=b-1) A[i][b+a-i-2]=1;
		else A[i][i]=1;	
	}
	vector<vector<int>> B(N,vector<int>(N,0)); cin >> a >> b;
	for(int i=0; i<N; ++i) {
		if(a-1<=i&&i<=b-1) B[i][b+a-i-2]=1;
		else B[i][i]=1;	
	}
	vector<vector<int>> C=matMul(B, A);
	vector<vector<int>> seq(N, vector<int>(N)); for(int i=0; i<N; ++i) seq[i][i]=i+1;
	vector<vector<int>> ans=matMul(power(C, K), seq);
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) if(ans[i][j]>0) cout << ans[i][j] << '\n';
}