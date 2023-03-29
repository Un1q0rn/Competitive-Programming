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
const int INF = 1e9;
struct EDGE{
    int v,c,f;
};
int main() {
    setIO("pump");
    int n,m;cin >> n >> m;
    vector<vector<EDGE>> adj(n+1);
    vector<int> flows;
    while(m--){
        int u,v,c,f;cin >> u >> v >> c >> f;
        adj[u].pb({v,c,f});
        adj[v].pb({u,c,f});
        flows.pb(f);
    }
    int ans = 0;
    for(auto f:flows){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> cost(n+1,INF);
        pq.push({0,1});
        cost[1] = 0;
        while(sz(pq)){
            int u = pq.top().s,w = pq.top().f;
            pq.pop();
            if(cost[u] != w) continue;
            for(auto x:adj[u]){
                int v = x.v,c =x.c,fl = x.f;
                if(fl < f) continue;
                if(cost[v] < cost[u]+c) continue;
                pq.push({cost[v] = cost[u]+c,v});
            }
        }
        if(cost[n] == INF) continue;
        int res = ((double)f/(double)(cost[n]))*(int)1e6;
        ans = max(res,ans);
    }
    cout << ans;
    return 0;
}
