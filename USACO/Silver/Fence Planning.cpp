#include <bits/stdc++.h>
using namespace std;

#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

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

const int N = 1e5+100;
vector<pi> pos;
vector<int> adj[N],net;
int visited[N];
void dfs(int cur){
    visited[cur] = 1;
    net.pb(cur);
    for(auto i:adj[cur]){
        if(!visited[i]){
            dfs(i);
        }
    }
}
int main() {
    setIO("fenceplan");
    int n,m;cin >> n >> m;
    pos.pb({0,0});
    for(int i=0;i<n;i++){
        int x,y;cin >> x >> y;
        pos.pb({x,y});
    }
    for(int i=0;i<m;i++){
        int u,v;cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int ans = INT_MAX;
    for(int i=1;i<=n;i++){
        int min_x = INT_MAX,max_x = 0,min_y = INT_MAX,max_y = 0;
        if(!visited[i]){
            dfs(i);
            for(auto j:net){
                int x = pos[j].f,y = pos[j].s;
                min_x = min(x,min_x);
                max_x = max(x,max_x);
                min_y = min(y,min_y);
                max_y = max(y,max_y);
            }
            ans = min(ans,2*((max_x-min_x)+(max_y-min_y)));
            net.clear();
        }
    }
    cout << ans;
    return 0;
}
