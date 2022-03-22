#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;

int main(void) {
	int l;
	string str;
	cin >> l >> str;
	vector<int> fail(l, 0);
	for(int i=1, j=0; i<l; ++i) {
		while(j>0 && str[i]!=str[j]) j=fail[j-1];
		if(str[i]==str[j]) fail[i]=++j;
	}
	cout << l-fail[l-1] << '\n';
}