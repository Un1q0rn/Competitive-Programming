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
    int a,b;cin >> a >> b;
    vector<vector<int>> dp(a+1,vector<int>(b+1,1e9));
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i == j){
                dp[i][j] = 0;
                continue;
            }
            for(int k=1;k<=i-1;k++){
                dp[i][j] = min(dp[i][j],dp[i-k][j]+dp[k][j]+1);
            }
            for(int k=1;k<=j-1;k++){
                dp[i][j] = min(dp[i][j],dp[i][j-k]+dp[i][k]+1);
            }
        }
    }
    cout << dp[a][b];
    return 0;
}
