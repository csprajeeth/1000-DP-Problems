// http://www.spoj.com/problems/ACPC10D/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int int64;

#define rep(i, N) for(int i=0; i<(int)N; i++)
#define all(X) (X).begin(), (X).end()

vvi DP;
vvi g(100010, vi());

int solve(int n) {
	DP = vvi(n, vi(3, INT_MAX));
	DP[0][1] = g[0][1];
	for(int i=0; i<n; i++) {
		for(int j=0; j<3; j++) {
			if (i==0 && j==0)
				continue;
			if (j+1 < 3) {
				DP[i][j+1] = min(DP[i][j+1], DP[i][j] + g[i][j+1]);
				if (i+1 < n) {
					DP[i+1][j+1] = min(DP[i+1][j+1], DP[i][j] + g[i+1][j+1]);
				}
			}
			if (j-1 >= 0 && i+1 < n) {
				DP[i+1][j-1] = min(DP[i+1][j-1], DP[i][j] + g[i+1][j-1]);
			}
			if (i+1 < n) {
				DP[i+1][j] = min(DP[i+1][j], DP[i][j] + g[i+1][j]);
			}
		}
	}
	return DP[n-1][1];
}

int main() {
#ifdef HOME
	freopen("in", "r", stdin);
#endif
	cin.sync_with_stdio(false);

	int n; 	int Case = 1;
	while(cin >> n) {
		if (n == 0)
			break;
		rep(i, n) {
			g[i].clear();
			rep(j, 3) {
				int a; cin >> a;
				g[i].push_back(a);
			}
		}
		cout << Case << ". " << solve(n) << endl;
		Case++;
	}

	return 0;
}
