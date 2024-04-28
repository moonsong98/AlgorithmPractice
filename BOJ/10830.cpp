#include<iostream>
#include<vector>

using namespace std;
typedef unsigned long long ull;
const int M=1000;

int n;
vector<vector<int>> matrix;

int calc(int a, int b) {
	return ((a%M) * (b%M))% M;
}

int add (int a, int b) {
	return ((a%M) + (b%M))% M;
}

vector<vector<int>> mMul(vector<vector<int>>& a, vector<vector<int>>& b) {
	vector<vector<int>> ret = vector<vector<int>>(n, vector<int>(n,0));
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			for(int l=0; l<n; ++l) {
				ret[i][j] = add(ret[i][j], calc(a[i][l],b[l][j]));
			}
		}
	}
	return ret;
}

vector<vector<int>> mul(ull m) {
	if(m==1) return matrix;
	if(m%2) {
		vector<vector<int>> minus1 = mul(m-1);
		return mMul(matrix, minus1);
	}
	vector<vector<int>> a = mul(m/2);
	return mMul(a,a);
}


int main(void) {
	ull b;
	cin >> n >> b;
	matrix=vector<vector<int>> (n, vector<int>());
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j) {
			int a;
			cin>>a;
			a%=1000;
			matrix[i].push_back(a);
		}
	
	vector<vector<int>> ans = mul(b);
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) cout << ans[i][j] << ' ';
		cout << '\n';
	}
}