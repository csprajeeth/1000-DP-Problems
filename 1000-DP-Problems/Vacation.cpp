// http://codeforces.com/problemset/problem/313/B
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int int64;

#define rep(i, N) for(int i=0; i<(int)N; i++)
#define all(X) (X).begin(), (X).end()


int solve(string &a, string &b) {
	int n = a.size(), m = b.size();
	vvi dp(n+1, vi(m+1, 0));
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if (a[i-1] == b[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	return dp[n][m];
}
int main() {
#ifdef HOME
	freopen("in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	string a, b;
	int Case = 1;
	while(getline(cin, a)) {
		if (a[0] == '#')
			break;
		getline(cin, b);
		cout << "Case #" << Case++ << ": you can visit at most "
				<< solve(a, b) << " cities." << endl;
	}
	return 0;
}
