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

int main() {
    setIO("piggyback");
    ll b,e,p;
    int n,m;
    cin >> b >> e >> p >> n >> m;
    vector<ll> bdist,edist,pdist;
    vector<vector<int>> adj(n);
    while(m--){
        int u,v;cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto dijkstra = [&](int src,ll d){
        vector<ll> dist(n,1e18);
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
        dist[src] = 0;
        pq.push({dist[src],src});
        while(sz(pq)){
            int u = pq.top().second;
            int w = pq.top().first;
            pq.pop();
            if(w != dist[u]) continue;
            for(auto v:adj[u]){
                if(dist[v] > d + w){
                    dist[v] = d + w;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
    };
    bdist = dijkstra(0,b);
    edist = dijkstra(1,e);
    pdist = dijkstra(n - 1,p);
    ll ans = 1e18;
    for(int i=0;i<n;i++){
        ans = min(ans,bdist[i] + edist[i] + pdist[i]);
    }
    cout << ans;
    return 0;
}
