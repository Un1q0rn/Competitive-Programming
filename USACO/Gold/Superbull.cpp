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
int main() {
    setIO("superbull");
    int n;cin >> n;
    vector<int> a(n);
    DSU dsu(n+1);
    for(auto &e:a) cin >> e;
    priority_queue<pair<int,pair<int,int>>> pq;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            pq.push({(a[i]^a[j]),{i,j}});
        }
    }
    ll ans = 0;
    while(sz(pq)){
        int u = pq.top().s.f,v = pq.top().s.s,w = pq.top().f;
        pq.pop();
        if(dsu.unite(u,v)){
            ans+=w;
            if(dsu.size(u) == n || dsu.size(v) == n){
                cout << ans;
                return 0;
            }
        }
    }
    return 0;
}
