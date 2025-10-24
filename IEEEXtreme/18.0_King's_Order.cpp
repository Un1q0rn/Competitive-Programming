#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define ll long long
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define pi pair<int,int>

void solve() {
    int n,m;cin >> n >> m;
    vector<int> a(n),indeg(n);
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    while(m--){
        int u,v;cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        indeg[v]++;
    }

    priority_queue<pi,vector<pi>,greater<pi>> pq;
    for(int i=0;i<n;i++){
        if(!indeg[i]){
            pq.push({a[i],i});
        }
    }

    vector<int> ans;
    while(sz(pq)){
        auto [g,u] = pq.top();
        pq.pop();
        ans.push_back(u);
        for(auto v:adj[u]){
            if(--indeg[v] == 0){
                pq.push({a[v],v});
            }
        }
    }

    if(sz(ans) == n){
        for(auto e:ans) cout << e + 1 << ' ';
    }
    else cout << -1;
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
