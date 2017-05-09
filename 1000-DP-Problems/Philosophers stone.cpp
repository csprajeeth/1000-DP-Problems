// http://www.spoj.com/problems/BYTESM2/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int int64;

#define rep(i, N) for(int i=0; i<(int)N; i++)
#define all(X) (X).begin(), (X).end()

int solve(vvi &v) {
	int n = v.size();
	int m = v.front().size();
	vvi dp(n, vi(m, INT_MIN));
	rep(j, m) {
		dp[0][j] = v[0][j];
	}
	rep(i, n-1) {
		rep(j, m) {
			if(j-1 >= 0)
				dp[i+1][j-1] = max(dp[i+1][j-1], v[i+1][j-1] + dp[i][j]);
			if(j+1 < m)
				dp[i+1][j+1] = max(dp[i+1][j+1], v[i+1][j+1] + dp[i][j]);
			dp[i+1][j] = max(dp[i+1][j], v[i+1][j] + dp[i][j]);
		}
	}
	return *max_element(all(dp.back()));
}

int main() {
#ifdef HOME
	freopen("in", "r", stdin);
#endif
	int t; cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		vvi v(n, vi());
		rep(i, n) {
			rep(j, m) {
				int a; cin >> a;
				v[i].push_back(a);
			}
		}
		cout << solve(v) << endl;
	}
	return 0;
}
