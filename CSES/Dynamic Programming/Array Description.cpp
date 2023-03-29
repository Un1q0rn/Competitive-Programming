#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) begin(x),end(x)
#define pb push_back
#define sz(x) (int)x.size()
const int MOD = 1e9+7;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin >> n >> m;
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for(int i=0;i<n;i++){
        int x;cin >> x;
        if(i == 0){
            if(x == 0){
                for(int j=0;j<=m;j++){
                    dp[i][j] = 1;
                }
            }
            else{
                dp[i][x] = 1;
            }
            continue;
        }
        if(x == 0){
            for(int j=1;j<=m;j++){
                for(int k=-1;k<=1;k++){
                    int jj = j+k;
                    if(jj < 1 || jj > m) continue;
                    dp[i][j] += dp[i-1][jj];
                    dp[i][j] %= MOD;
                }
            }
        }
        else{
            for(int k=-1;k<=1;k++){
                int jj = x+k;
                if(jj < 1 || jj > m) continue;
                dp[i][x] += dp[i-1][jj];
                dp[i][x] %= MOD;
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=m;i++){
        ans+=dp[n-1][i];
        ans%=MOD;
    }
    cout << ans;
    return 0;
}
