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
vector<vector<pair<int,char>>> adj;
vector<int> color,vis;
ll cnt = 0,check = 0;
void dfs(int u,int g){
    if(check) return;
    vis[u] = 1;
    color[u] = g;
    for(auto x:adj[u]){
        int v = x.f,w = x.s;
        if(vis[v]){
            if((color[v] == g && w == 'D') || (color[v] != g && w == 'S')){
                check = 1;
                return ;
            }
        }
        else{
            dfs(v,(w == 'S' ? g:g^1));
        }
    }
}
int main() {
    setIO("revegetate");
    int n,m;cin >> n >> m;
    adj.resize(n+1);
    color.assign(n+1,-1);
    vis.resize(n+1);
    while(m--){
        char w;
        int u,v;cin >> w >> u >> v;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        dfs(i,0);
        cnt++;
    }
    if(check) cout << 0 ;
    else{
        cout << 1 ;
        for(int i=0;i<cnt;i++){
            cout << 0;
        }
    }
    return 0;
}
