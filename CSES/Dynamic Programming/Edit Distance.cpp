#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) begin(x),end(x)
#define pb push_back
#define sz(x) (int)x.size()
const int INF = 1e9;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s,t;cin >> s >> t;
    int n = sz(s),m = sz(t);
    vector<vector<int>>  dp(n+1,vector<int>(m+1,INF));
    dp[0][0] = 0;
    for(int i=0;i<=n;i++) for(int j=0;j<=m;j++){
        if(i) dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
        if(j) dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
        if(i && j) dp[i][j] = min(dp[i][j],dp[i-1][j-1]+(s[i-1] != t[j-1]));
    }
    cout << dp[n][m];
    return 0;
}
