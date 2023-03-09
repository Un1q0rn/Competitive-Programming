#include <bits/stdc++.h> 
using namespace std;

#define vi(x)  vector<x>
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,b,a) for(int i=b;i>=a;i--)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define pb push_back
#define setdecimal(x) cout << fixed << setprecision(x)

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
#define ll long long int

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
vector<vector<int>> adj,comps;
vector<int> group;
int n,m,idx;
void init(){
    adj.resize(n+1);
    group.resize(n+1);
    for(int i=1;i<=n;i++){
        adj[i].clear();
        group[i] = -1;
    }
    for(int i=0;i<idx;i++){
        comps[i].clear();
    }
    idx = 0;
}
void dfs(int u){
    group[u] = idx;
    for(auto v:adj[u]){
        if(group[v] == idx) continue;
        dfs(v);
    }
}
ll cost(int a,int b){
    ll res = 1e18;
    for(auto v:comps[a]){
        int now = lower_bound(all(comps[b]),v)-comps[b].begin();
        if(now > 0){
            res = min(res,(ll)abs(v-comps[b][now-1]));
        }
        if(now < sz(comps[b])){
            res = min(res,(ll)abs(v-comps[b][now]));
        }
    }
    return res*res;
}
void solve(){
    cin >> n >> m;
    init();
    while(m--){
        int u,v;cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i=1;i<=n;i++){
        if(group[i] != -1) continue;
        dfs(i);
        idx++;
    }
    comps.resize(idx);
    for(int i=1;i<=n;i++){
        comps[group[i]].pb(i);
    }
    ll ans = 1e18;
    for(int i=0;i<idx;i++){
        ans = min(ans,cost(i,group[1])+cost(i,group[n]));
    }
    cout << ans << '\n';
} 
int main() {
    setIO("");
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
