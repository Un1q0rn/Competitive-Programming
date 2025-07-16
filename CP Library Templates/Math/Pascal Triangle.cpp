#include <bits/stdc++.h>
using namespace std;

int binomial(int n, int k) {
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
		if (i <= k) { dp[i][i] = 1; }
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= min(i, k); j++) {
			if (i != j) {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]);
			}
		}
	}

	return dp[n][k];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
	int n,k;cin >> n >> k;
  cout << binomial(n,k);
}
