// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=503
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int int64;

#define rep(i, N) for(int i=0; i<(int)N; i++)
#define all(X) (X).begin(), (X).end()

int solve(vi &v) {
	if (v.size() == 0)
		return 0;
	int tot = accumulate(all(v), 0);
	int n = v.size();
	int m = tot/2;
	vvi DP(n, vi(m+1, 0));
	rep(i, n)
		DP[i][0] = 1;
	if (v[0] <=m )
		DP[0][v[0]] = 1;
	for(int i=1; i<n; i++) {
		for(int j=1; j<=m; j++) {
			DP[i][j] = DP[i-1][j];
			if (j-v[i]>=0)
				DP[i][j] |= DP[i-1][j-v[i]];
		}
	}
	int c1 = 0;
	for(int i=m; i>=0; i--) {
		if (DP[n-1][i] == 1) {
			c1 = i;
			break;
		}
	}
	int c2 = tot - c1;
	return abs(c1-c2);
}

int main() {
#ifdef HOME
	freopen("in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vi v;
		rep(i, n) {
			int a; cin >> a;
			v.push_back(a);
		}
		cout << solve(v) << "\n";
	}
	return 0;
}
