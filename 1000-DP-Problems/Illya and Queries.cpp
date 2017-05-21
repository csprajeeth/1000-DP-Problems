// http://codeforces.com/problemset/problem/313/B
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int int64;

#define rep(i, N) for(int i=0; i<(int)N; i++)
#define all(X) (X).begin(), (X).end()

vi dp;
void solve(string s) {
	int n = s.size();
	dp = vi(n, 0);
	for (int i = 1; i < n; i++) {
		dp[i] = dp[i - 1];
		if (s[i] == s[i - 1])
			dp[i]++;
	}
}

int main() {
#ifdef HOME
	freopen("in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	string s;
	cin >> s;
	solve(s);

	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		cout << dp[b] - dp[a] << endl;
	}
	return 0;
}
