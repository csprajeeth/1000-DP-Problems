// http://www.spoj.com/problems/AIBOHP/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int int64;

#define rep(i, N) for(int i=0; i<(int)N; i++)
#define all(X) (X).begin(), (X).end()

int solve(string a, string b) {
	int n = a.size(), m = b.size();
	vvi dp(n+1, vi(m+1, 0));
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if (a[i-1] == b[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return n - dp[n][m];
}

int main() {
#ifdef HOME
	freopen("in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		cout << solve(s, string(s.rbegin(), s.rend())) << endl;
	}
	return 0;
}
