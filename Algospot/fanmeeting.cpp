#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

// A += B*(10^k)
void addTo(vector<int> A, vector<int>& B, int k) {
	int origi
}

void normalize(vector<int>& num) {
	num.push_back(0);
	int size = num.size();
	for(int i = 0; i < size -1; ++i) {
		if(num[i] < 0) {
			int borrow = (abs(num[i]) + 9) / 10;
			num[i+1] -= borrow;
			num[i] += borrow * 10;
		}
		else {
			num[i + 1] += num[i] / 10;
			num[i] % 10;
		}
	}
	while(num.size() > 1 && num.back() == 0)
		num.pop_back();
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	vector<int> c(a. size() + b.size() + 1, 0);
	int sizeA = a.size(), sizeB = b.size();
	
	for(int i = 0; i < sizeA; ++i)
		for(int j = 0; j < sizeB; ++j)
			c[i + j] += a[i] * b[j];
	
	normalize(c);
	return c;
}


vector<int> karatsuba(vector<int>& A, vector<int>& B) {
	int an = A.size(), bn = B.size();	
	if(an < bn) return karatsuba(B, A);
	if(an == 0 || bn == 0) return vector<int>();
	
	if(an <= 50) return multiply(A, B);
	
	int half = an/2;
	
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin()+min<int>(b.size(), half), b.end());
	
	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);
	
	
}

void solve() {
	string fans;
	string singers;
	
	cin >> fans;
	cin >> singers;
	
	int len2 = singers.size(), len1 = fans.size();
	vector<int> A, B;
	
	for(int i = 0; i < len1; ++i)
		A.push_back(fans[i] == 'M');

	for(int i = 0; i < len2; ++i)
		A.push_back(singers[len2 - i - 1] == 'M');
	
	vector<int> result = karatsuba(A, B);
	
	int ret = 0;
	for(int i = len1; i < len2; ++i)
		ret += (result[i] == 0);
	return ret;
}

int main(void) {
	cin.sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) solve();
}