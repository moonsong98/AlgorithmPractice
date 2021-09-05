#include<iostream>

using namespace std;

long long x[2*100*1000+11];
long long y[2*100*1000+11];


int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	while(t--){
		int numX;
		cin>>numX;
		for(int i=0; i<numX; ++i)
			cin>>x[i];
		y[0]=x[0]&1||x[0]==0?0:1;
		for(int i=1; i<numX; ++i) {
			y[i]=x[i]^y[0];
				int d=0;
				for(int j=0;j<63;++j)
					if(y[i]&(long long)1<<j) d=j;
				y[i]-=(long long)1<<d;
		}
		for(int i=0; i<numX;++i)
			cout<<y[i]<<' ';
		cout<<'\n';
	}
}