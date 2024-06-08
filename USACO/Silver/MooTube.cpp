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
    setIO("mootube");
    int n,Q;cin >> n >> Q;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v,w;cin >> u >> v >> w;
        u--,v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    while(Q--){
        int s,w;cin >> w >> s;
        s--;
        int res = 0;
        vector<int> vis(n);
        vis[s] = 1;
        queue<int> q;
        q.push(s);
        while(sz(q)){
            int u = q.front();
            q.pop();
            for(auto v:adj[u]){
                if(vis[v.first] || v.second < w) continue;
                vis[v.first] = 1;
                res++;
                q.push(v.first);
            }
        }
        cout << res << '\n';
    }
    return 0;
}
