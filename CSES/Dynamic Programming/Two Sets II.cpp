#include <bits/stdc++.h>
using namespace std;
 
#define ld long double 
#define ll long long int
#define pi pair<int,int>
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

const int MOD = 1e9 + 7;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    int w = n * (n+1) / 2;
    if(w % 2){
        cout << 0;
        return 0;
    }
    w >>= 1;
    vector<vector<int>> dp(n+1,vector<int>(w+1));
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            dp[i][j] = dp[i - 1][j];
            if(j - i >= 0) dp[i][j] += dp[i - 1][j - i];
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n][w];
    return 0;
}
