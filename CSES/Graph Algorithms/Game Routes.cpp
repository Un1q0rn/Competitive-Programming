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
    vector<vector<int>> adj(n+1),rev_adj(n+1);
    vector<int> dp(n+1),indeg(n+1);
    while(m--){
        int u,v;cin >> u >> v;
        adj[u].pb(v);
        rev_adj[v].pb(u);
        indeg[v]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indeg[i] == 0) q.push(i);
    }
    dp[1] = 1;
    while(sz(q)){
        int u = q.front();
        q.pop();
        for(auto v:adj[u]){
            indeg[v]--;
            if(indeg[v] == 0) q.push(v);
        }
        for(auto v:rev_adj[u]){
            dp[u]+=dp[v];
            dp[u] %= MOD;
        }
    }
    cout << dp[n];
    return 0;
}
