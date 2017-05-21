// http://www.spoj.com/problems/ROCK/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int int64;

#define rep(i, N) for(int i=0; i<(int)N; i++)
#define all(X) (X).begin(), (X).end()

int solve(vi &v) {
	int n = v.size();
	vi dp(n+1, 0);
	for(int i=1; i<=n; i++) {
		dp[i] = dp[i-1];
		int zero = 0, one = 0;
		for(int j=i; j>=1; j--) {
			if(v[j-1] == 0) zero++;
			else one++;
			if (one > zero) {
				dp[i] = max(dp[i], (i-j+1) + dp[j-1]);
			}
		}
	}
	return dp[n];
}

int main() {
#ifdef HOME
	freopen("in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		cin.ignore();
		vi v;
		rep(i, n) {
			char c;	cin >> c;
			v.push_back(c - '0');
		}
		cout << solve(v) << endl;
	}
	return 0;
}
