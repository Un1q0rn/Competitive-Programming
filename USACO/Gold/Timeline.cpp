
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
    setIO("timeline");
    int n,m,c;cin >> n >> m >> c;
    vector<vector<pair<int,int>>> adj(n);
    vector<int> a(n),ind(n);
    for(auto &e:a) cin >> e;

    while(c--){
        int u,v,w;cin >> u >> v >> w;
        adj[--u].push_back({--v,w});
        ind[v]++;
    }

    queue<int> q;
    for(int i=0;i<n;i++){
        if(ind[i] == 0) q.push(i);
    }

    vector<int> ans = a;
    while(sz(q)){
        int u = q.front();
        q.pop();
        for(auto [v,w]:adj[u]){
            ans[v] = max(ans[v],ans[u] + w);
            if(--ind[v] == 0){
                q.push(v);
            }
        }
    }

    for(auto e:ans) cout << e << '\n';
    return 0;
}
