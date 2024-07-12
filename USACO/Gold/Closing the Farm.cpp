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

struct DSU{
    vector<int> e;
    DSU(int n) : e(n,-1){}
    int root(int i) {return e[i] < 0 ? i:e[i] = root(e[i]);}
    bool same(int a,int b) {return root(a) == root(b);}
    int size(int i) {return -e[root(i)];}
    bool unite(int a,int b){
        a = root(a),b = root(b);
        if(a == b) return false;
        if(e[a] > e[b]) swap(a,b);
        e[a] += e[b];
        e[b] = a;
        return true;
    }
};

int main() {
    setIO("closing");
    int n,m;cin >> n >> m;
    DSU dsu(n);
    vector<vector<int>> adj(n);
    vector<int> mark(n),qry(n);
    vector<string> ans;
    while(m--){
        int u,v;cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        cin >> qry[i];
        qry[i]--;
    }
    reverse(all(qry));
    mark[qry[0]] = 1;
    ans.push_back("YES");
    for(int i=1;i<n;i++){
        int u = qry[i];
        mark[u] = 1;
        for(auto v:adj[u]){
            if(!mark[v]) continue;
            dsu.unite(u,v);
        }
        ans.push_back(dsu.size(u) == i+1 ? "YES":"NO");
    }
    reverse(all(ans));
    for(auto e:ans) cout << e << '\n';
    return 0;
}
