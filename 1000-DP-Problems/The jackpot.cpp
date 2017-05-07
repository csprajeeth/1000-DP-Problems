// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1625
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
	int n;
	while(cin >> n) {
		if (n==0) break;
		vi A;
		rep(i, n) {
			int a ;cin >> a;
			A.push_back(a);
		}
		int ans = A[0], suffix_so_far = A[0];
		for(int i=1; i<n; i++) {
			suffix_so_far = max(A[i], suffix_so_far + A[i]);
			ans = max(ans, suffix_so_far);
		}
		if (ans <= 0)
			cout << "Losing streak." << endl;
		else
			cout << "The maximum winning streak is " << ans << "." << endl;
	}
	return 0;
}
