// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1605
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int int64;

#define rep(i, N) for(int i=0; i<(int)N; i++)
#define all(X) (X).begin(), (X).end()

int dp[30][500];

bool subsetSum(const vi &v, int sum) {
	int n = v.size();
	for (int i = 0; i <= sum; i++) {
		dp[0][i] = (v[0] == i);
	}
	for (int i = 0; i < n; i++) {
		dp[i][0] = true;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= sum; j++) {
			dp[i][j] =
					(j - v[i] >= 0) ?
							(dp[i - 1][j - v[i]] | dp[i - 1][j]) : dp[i - 1][j];
		}
	}
	return dp[n-1][sum];
}

int main() {
#ifdef HOME
	freopen("in", "r", stdin);
#endif
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	while (t--) {
		getline(cin, s);
		istringstream sin(s);
		int a;
		vi v;
		while (sin >> a) {
			v.push_back(a);
		}
		int tot = accumulate(all(v), 0);
		if (v.size() == 0) {
			cout << "YES";
		} else if (tot % 2 != 0 ) {
			cout << "NO";
		} else {
			if (subsetSum(v, tot / 2))
				cout << "YES";
			else
				cout << "NO";
		}
		cout << endl;
	}
	return 0;
}
