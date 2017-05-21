// http://www.spoj.com/problems/RENT/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unsigned long long int uint64;

#define rep(i, N) for(int i=0; i<(int)N; i++)
#define all(X) (X).begin(), (X).end()
#define MOD 1000000

struct Interval {
	int s, e, p;
	Interval(int a, int b, int c) {
		s = a;
		e = b;
		p = c;
	}
	bool operator<(const Interval &rhs) const {
		if (e == rhs.e)
			return s < rhs.s;
		return e < rhs.e;
	}
};

bool comp(const Interval &a, int s) {
	return a.e <= s;
}

int solve(vector<Interval> &v) {
	int n = v.size();
	vi DP(n, 0);
	DP[0] = v[0].p;
	for(int i=1; i<n; i++) {
		auto it = lower_bound(all(v), v[i].s, comp);
		int ind = -1;
		if (it != v.end()) {
			ind = it - v.begin();
			ind--;
		}
		DP[i] = max(DP[i-1], v[i].p + (ind >= 0 ? DP[ind] : 0));
	}
	return DP[n-1];
}

int main() {
#ifdef HOME
	freopen("in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		vector<Interval> v;
		int n; cin >> n;
		rep(i, n) {
			int a, b, c;
			cin >> a >> b >> c;
			v.push_back(Interval(a, a+b, c));
		}
		sort(all(v));
		cout << solve(v) << endl;
	}
	return 0;
}
