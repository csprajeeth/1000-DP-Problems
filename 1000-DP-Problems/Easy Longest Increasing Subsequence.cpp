// http://www.spoj.com/problems/ELIS/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;

#define rep(i, n) for(int i=0; i<(int)n; i++)
#define all(X) (X).begin(),(X).end()

int main() {
#ifdef HOME
	freopen("in", "r", stdin);
#endif
	int n; cin >> n;
	vi v;
	rep(i, n) {
		int a; cin >> a;
		v.push_back(a);
	}
	vi dp(n, 1);
	for (int i=1; i<n; i++) {
		for (int j=i-1; j >=0; j--) {
			if (v[j] < v[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	cout << *max_element(all(dp));
	return 0;
}
