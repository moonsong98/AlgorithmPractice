#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	string N;
	while (true) {
		cin >> N;
		if(N==".") break;
		int size=sz(N);
		vector<int> fail(size, 0);
		for(int i=1, j=0; i<size; ++i) {
			while(j>0&&N[i]!=N[j]) j=fail[j-1];
			if(N[i]==N[j]) fail[i]=++j;
		}
		int i=size;
		if(size%(size-fail[size-1])) cout << 1 << '\n';
		else cout << size/(size-fail[size-1]) << '\n';
	}
}
