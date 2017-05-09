// http://www.spoj.com/problems/WACHOVIA/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int int64;

#define rep(i, N) for(int i=0; i<(int)N; i++)
#define all(X) (X).begin(), (X).end()

int solve(vi &w, vi &v, int K) {
	int n = v.size();
	vvi dp(n, vi(K+1, 0));
	for(int i=0; i<n; i++)
		dp[i][0] = 0;
	for(int i=0; i<=K; i++)
		dp[0][i] = (w[0] <= i ? v[0] : 0);

	for(int i=1; i<n; i++) {
		for(int j=1; j<=K; j++) {
			dp[i][j] = dp[i-1][j];
			if (w[i] <= j)
				dp[i][j] = max(dp[i][j], v[i] + dp[i-1][j-w[i]]);
		}
	}
	return dp[n-1][K];
}

int main() {
#ifdef HOME
	freopen("in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	int t; cin >> t;
	while(t--) {
		vi v, w;
		int K, N;
		cin >> K >> N;
		rep(i, N) {
			int a, b;
			cin >> a >> b;
			w.push_back(a);
			v.push_back(b);
		}
		cout << "Hey stupid robber, you can get " << solve(w, v, K) << "." << "\n";
	}
	return 0;
}
