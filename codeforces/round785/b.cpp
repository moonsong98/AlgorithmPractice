#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;

int main(void) {
	int t; cin >> t;
	while(t--) {
		string str;
		cin >> str;
		vector<int> pos(26, -1);
		vector<bool> exist(26, false);
		for(int i=0; i<sz(str); ++i)
			exist[str[i]-'a']=true;
		bool ans=true;
		for(int i=0; i<sz(str); ++i) {
			int p=str[i]-'a';
			bool valid=true;
			for(int j=0; j<26; ++j) 
				if(exist[j]&&!(pos[str[i]-'a']<=pos[j]&&pos[j]<i))
					valid=false;
			if(valid==false) ans=valid;
			pos[str[i]-'a']=i;
		}
		cout << (ans?"YES":"NO") << '\n';
	}
}