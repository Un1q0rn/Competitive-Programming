#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) begin(x),end(x)
#define pb push_back
#define sz(x) (int)x.size()
#define s second
#define f first

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,x;cin >> n >> x;
    vector<int> h(n+1),s(n+1);
    for(int i=1;i<=n;i++) cin >> h[i];
    for(int i=1;i<=n;i++) cin >> s[i];
    vector<vector<int>> dp(n+1,vector<int>(x+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            dp[i][j] = dp[i-1][j];
            if(j-h[i] >= 0) dp[i][j] = max(dp[i][j],dp[i-1][j-h[i]]+s[i]);
        }
    }
    cout << dp[n][x];
    return 0;
}
