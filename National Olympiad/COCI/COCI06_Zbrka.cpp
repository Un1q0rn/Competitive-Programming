#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) begin(x),end(x)
#define sz(x) (int)x.size()
#define ul unsigned long long

const int MOD = 1e9 + 7;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n,c;cin >> n >> c;
    vector<vector<ll>> dp(2,vector<ll>(c + 1));

    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        int cur = i % 2;
        int prev = (i - 1) % 2;
        for(int j=0;j<=c;j++){
            dp[cur][j] = ((j > 0 ? dp[cur][j - 1] : 0) + dp[prev][j] - (j >= i ? dp[prev][j - i] : 0) + MOD) % MOD;
        }
    }
    cout << dp[n % 2][c];
    return 0;
}
