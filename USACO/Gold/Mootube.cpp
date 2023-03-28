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
    vector<int> pa,sz;
    DSU(int n){
        pa.resize(n);
        sz.resize(n);
        for(int i=0;i<n;i++){
            pa[i] = i;
            sz[i] = 1;
        }
    }
    int root(int x) {return (x == pa[x] ? x:pa[x] = root(pa[x]));}
    int size(int x) {return sz[root(x)];}
    bool unite(int a,int b){
        a = root(a),b = root(b);
        if(a == b) return false;
        if(sz[a] < sz[b]) swap(a,b);
        sz[a] += sz[b];
        pa[b] = a;
        return true;
    }
};
struct EDGE{
    int u,v,w;
    bool operator <(const EDGE&o) const{
        return w > o.w;
    }
};
struct QRY{
    int k,v,idx;
    bool operator <(const QRY&o) const{
        return k > o.k;
    }
};
int main() {
    setIO("mootube");
    int n,q;cin >> n >> q;
    vector<EDGE> edge;
    for(int i=0;i<n-1;i++){
        int u,v,w;cin >> u >> v >> w;
        edge.pb({u,v,w});
    }
    sort(all(edge));
    vector<QRY> qry;
    for(int i=0;i<q;i++){
        int k,v;cin >> k >> v;
        qry.pb({k,v,i});
    }
    sort(all(qry));
    vector<int> ans(q);
    int idx = 0;
    DSU dsu(n+1);
    for(auto x:qry){
        int k = x.k;
        while(idx < sz(edge) && k <= edge[idx].w){
            int u = edge[idx].u,v = edge[idx].v;
            dsu.unite(u,v);
            idx++;
        }
        int v = x.v,p = x.idx;
        ans[p] = dsu.size(v)-1;
    }
    for(auto e:ans) cout << e << '\n';
    return 0;
}
