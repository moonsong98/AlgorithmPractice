#include<iostream>
#include<vector>
#include<utility>
#include<cmath>

using namespace std;

double ans=-1;
vector<pair<double,double>> points;
int n;

double calc(vector<int>& chosen) {
	double x=0, y=0;
	int pos=0;
	for(int i=0; i<n; ++i) {
		if(pos<chosen.size() && chosen[pos]==i) {
			x+=points[i].first;
			y+=points[i].second;
			pos++;
		}
		else {
			x-=points[i].first;
			y-=points[i].second;
		}
	}
	return sqrt(pow(x,2) + pow(y,2));
}

void solve(vector<int>& chosen) {
	if(chosen.size()==n/2) {
		double cand = calc(chosen);
		if(ans==-1 || ans > cand) ans = cand;
		return;
	}
	for(int i=chosen.size() == 0 ? 0 : chosen.back()+1; i<n; ++i) {
		chosen.push_back(i);
		solve(chosen);
		chosen.pop_back();
	}
}

int main(void) {
	int t;
	scanf("%d", &t);
	while(t--) {
		points=vector<pair<double,double>>();
		vector<int> chosen;
		ans=-1;
		scanf("%d", &n);
		
		for(int i=0; i<n; ++i) {
			double x, y;
			scanf ("%lf %lf", &x, &y);
			points.push_back({x,y});
		}
		solve(chosen);
		printf("%lf\n", ans);
	}
}