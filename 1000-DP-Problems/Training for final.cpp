// http://www.spoj.com/problems/TRIKA/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int int64;

#define rep(i, N) for(int i=0; i<(int)N; i++)
#define all(X) (X).begin(), (X).end()

int solve(vvi &v, int x, int y) {
	int n = v.size();
	int m = v.front().size();
	vvi dp = v;
	rep(i, n) {
		rep(j, m) {
			if ((i < x || j < y) || (i==x && j==y))
				continue;
			int a = (j-1 >= y ? dp[i][j-1] - v[i][j] : INT_MIN);
			int b = (i-1 >= x ? dp[i-1][j] - v[i][j] : INT_MIN);
			dp[i][j] = max(a, b);
		}
	}
	return dp[n-1][m-1];
}

int main() {
#ifdef HOME
	freopen("in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	int n, m;
	while(cin >> n >> m) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		vvi v(n, vi());
		rep(i, n) {
			rep(j, m) {
				int a; cin >> a;
				v[i].push_back(a);
			}
		}
		int ans = solve(v, x, y);
		if(ans >= 0)
			cout << "Y " << ans << "\n";
		else
			cout << "N\n";
	}
	return 0;
}

// Test data
//2 2
//1 2
//2 2
//50 1
//
//2 2
//2 2
//2 2
//50 1
//
//2 2
//2 1
//2 2
//1 50
//
//2 2
//2 1
//2 2
//50 1

