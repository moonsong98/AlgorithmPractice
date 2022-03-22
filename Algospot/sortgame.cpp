#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

map<vi, int> m;

void preCalc() {
	for(int i=1; i<=8; ++i) {
		vector<int> v(i);
		for(int j=0; j<i; ++j) v[j]=j;
		queue<vi> q;
		q.push(v);
		m[v]=0;
		while(!q.empty()) {
			vi t=q.front();
			int d=m[t];
			q.pop();
			for(int k=0; k<i; ++k)
				for(int l=k+2; l<=i; ++l) {
					reverse(t.begin()+k, t.begin()+l);
					if(m.count(t)==0) {
						q.push(t);
						m[t]=d+1;
					}
					reverse(t.begin()+k, t.begin()+l);
				}
		}
	}
}

int main(void) {
	preCalc();
	int t;
	cin >> t;
	while(t--) {
		int size;
		cin >> size;
		vi arr(size), tmp(size);
		for(int i=0; i<size; ++i) {
			cin >> arr[i];
			tmp[i]=arr[i];
		}
		sort(tmp.begin(), tmp.end());
		for(int i=0; i<size; ++i)
			arr[i]=lower_bound(tmp.begin(), tmp.end(), arr[i])-tmp.begin();
		cout << m[arr] << '\n';
	}
}