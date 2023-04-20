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
    int n,m;cin >> n >> m;
    vector<vector<vector<int>>> dp(2,vector<vector<int>>(n+1,vector<int>(m+1)));
    string s,t;cin >> s >> t;
    int ans = 0;
    for(int i=0;i<=n;i++) fill(all(dp[0][i]),-1);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i>0){
                if(s[i-1] == 'I') dp[0][i][j] = max(dp[0][i][j],dp[1][i-1][j]+1);
                else dp[1][i][j] = max(dp[1][i][j],dp[0][i-1][j]+1);
            }
            if(j>0){
                if(t[j-1] == 'I') dp[0][i][j] = max(dp[0][i][j],dp[1][i][j-1]+1);
                else dp[1][i][j] = max(dp[1][i][j],dp[0][i][j-1]+1);
            }
            ans = max(ans,dp[0][i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}

