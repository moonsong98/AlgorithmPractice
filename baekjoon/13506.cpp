#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;

int main(void) {
	string str;
	cin >> str;
	int size=sz(str);
	vector<int> fail(size, 0);
	vector<bool> exist(size+1, false);
	for(int i=1, j=0; i<size; ++i) {
		while(j>0 && str[i]!=str[j]) j=fail[j-1];
		if(str[i]==str[j]) fail[i]=++j;
		if(i!=size-1) 
			exist[fail[i]]=true;
	}
	int j=fail[size-1];
	while(j>0) {
		if(exist[j]) {
			cout << string(str.begin(), str.begin()+j) << '\n';
			return 0;
		}
		j=fail[j-1];
	}
	cout << -1 << '\n';
}