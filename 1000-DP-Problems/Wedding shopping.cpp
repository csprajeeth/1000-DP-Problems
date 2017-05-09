// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2445
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef long long int int64;
typedef unsigned long long int uint64;

#define rep(i, n) for(int i=0; i<(int)n; i++)
#define all(X) (X).begin(),(X).end()

vvi v;
int M, N;
int solve() {
	vector<vb> dp(N, vb(M+1, false));
	for(auto x : v[0]) {
		if (x >= 0 && x <= M)
			dp[0][x] = true;
	}

	for(int i=1; i<N; i++) {
		for(int j=0; j<=M; j++) {
			for(auto x : v[i]) {
				if (x <= j)
					dp[i][j] = dp[i][j] | dp[i-1][j-x];
			}
		}
	}

	for(int i=M; i>=0; i--)
		if(dp[N-1][i])
			return i;
	return -1;
}

int main() {
#ifdef HOME
	freopen("in", "r", stdin);
#endif
	int t;
	cin >> t;
	while(t--) {
		cin >> M >> N;
		v = vvi(N, vi());
		rep(i, N) {
			int c; cin >> c;
			while(c--) {
				int a; cin >> a;
				v[i].push_back(a);
			}
		}
		int ans = solve();
		if (ans == -1)
			cout << "no solution" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
