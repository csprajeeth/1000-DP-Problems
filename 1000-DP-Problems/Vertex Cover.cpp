// http://www.spoj.com/problems/PT07X/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int int64;

#define rep(i, N) for(int i=0; i<(int)N; i++)
#define all(X) (X).begin(), (X).end()

vvi g;
vi dp[2];
vi visited;

void dfs(int src) {
	visited[src] = 1;
	dp[0][src] = 0; // if this node is excluded, then include  all children
	dp[1][src] = 1; // if this node is included, then may of may not include all children
	for(auto x : g[src]) {
		if (visited[x] == 0) {
			dfs(x);
			dp[0][src] += dp[1][x];
			dp[1][src] += min(dp[0][x], dp[1][x]);
		}
	}
}

int solve() {
	int n = g.size();
	dp[1] = dp[0] = vi(n, 0);
	visited = vi(n, 0);
	dfs(0);
	return min(dp[0][0], dp[1][0]);
}

int main() {
#ifdef HOME
	freopen("in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	g = vvi(n, vi());
	rep(i, n-1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cout << solve() << endl;
	return 0;
}
