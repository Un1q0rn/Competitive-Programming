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

struct A{
    int u;
    ll w;
    bool operator < (const A & o) const{
        return w > o.w;
    }
};
int main() {
    setIO("shortcut");
    int n,m,t;cin >> n >> m >> t;
    vector<ll> a(n),dist(n,1e9),prev(n,-1),freq(n);
    for(auto &e:a) cin >> e;
    vector<vector<pair<int,ll>>> adj(n);
    while(m--){
        int u,v;
        ll w;cin >> u >> v >> w;
        u--,v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    priority_queue<A> pq;
    pq.push({0,0});
    dist[0] = 0;
    while(sz(pq)){
        int u = pq.top().u;
        ll d = pq.top().w;
        pq.pop();
        if(dist[u] != d) continue;
        for(auto [v,w]:adj[u]){
            if(d + w < dist[v]){
                dist[v] = d + w;
                prev[v] = u;
                pq.push({v,dist[v]});
            }
            else if(d + w == dist[v] && prev[v] > u){
                prev[v] = u;
                pq.push({v,dist[v]});
            }
        }
    }
    for(int i=0;i<n;i++){
        int now = i;
        while(prev[now] != -1){
            freq[now] += a[i];
            now = prev[now];
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans,freq[i] * (dist[i] - t));
    }
    cout << ans;
    return 0;
}
