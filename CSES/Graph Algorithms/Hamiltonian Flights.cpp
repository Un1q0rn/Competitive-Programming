#include <bits/stdc++.h>
using namespace std;
 
#define ull unsigned long long
#define ll long long int
#define pi pair<int,int>
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

const int MOD = 1e9+7;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin >> n >> m;
    vector<vector<int>> adj(n),dp(1<<n,vector<int>(n));
    while(m--){
        int u,v;cin >> u >> v;
        u--,v--;
        adj[v].push_back(u);
    }
    dp[1][0] = 1;
    for(int p=2;p<(1<<n);p++){
        if(p & (1<<(n-1)) && p != (1<<n)-1) continue;
        for(int u=0;u<n;u++){
            if(!(p & (1<<u))) continue;
            for(auto v:adj[u]){
                if(!(p & (1<<v))) continue;
                dp[p][u] += dp[p^(1<<u)][v];
                dp[p][u] %= MOD;
            }
        }
    }
    cout << dp[(1<<n)-1][n-1];
    return 0;
}
