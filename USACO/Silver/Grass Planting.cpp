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

const int N = 1e5;
vi(int) adj[N];

int main() {
    setIO("planting");
    int n;cin >> n;
    int ans = 0;
    for(int i=0;i<n-1;i++){
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        int mx = max(adj[u].size(),adj[v].size());
        ans = max(mx,ans);
    }
    cout << ans+1;
    return 0;
}
