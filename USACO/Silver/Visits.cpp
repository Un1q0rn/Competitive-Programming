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
const int N = 1e5;
vector<int> adj[N];
int n,a[N],v[N],vis[N];
ll ans;
void dfs(int u){
    if(vis[u]) return ;
    vis[u] = 1;
    for(auto k:adj[u]){
        dfs(k);
    }
}
int solve(int u){
    int x = a[u];
    int y = a[x];
    while(x != y){
        x = a[x];
        y = a[a[y]];
    }
    int mn = v[x];
    x = a[x];
    while(x != y){
        mn = min(mn,v[x]);
        x = a[x];
    }
    dfs(x);
    return mn;
}
int main() {
    setIO("");
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i] >> v[i];
        a[i]--;
        adj[a[i]].push_back(i);
        ans += v[i];
    }
    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        ans -= solve(i);
    }
    cout << ans;
    return 0;
}
