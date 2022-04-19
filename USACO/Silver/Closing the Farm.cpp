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
const int N = 1e5+10;
vector<int> adj[N];
vector<bool> visited(N,false);
vector<bool> closed(N,false);
int pa[N];
int nodes =0 ;
void dfs(int u){
    if(visited[u] || closed[u]) return;
    nodes++;
    visited[u] = true;
    for(auto v:adj[u]){
        if(!visited[v]) dfs(v);
    }
    return;
}


int main() {
    setIO("closing");
    int n,m;cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v;cin >> u >> v;
        adj[u].pb(v);adj[v].pb(u);
    }
    vector<int> ord(n);
    for(auto &e:ord){
        cin >> e;
    }
    dfs(1);
    if(nodes == n){
        cout << "YES\n";
    }
    else cout << "NO\n";
    for(int i=0;i<n-1;i++){
        nodes = 0;
        closed[ord[i]] = true;
        fill(visited.begin(),visited.end(),false);
        dfs(ord[n-1]);
        if(nodes == n-i-1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
