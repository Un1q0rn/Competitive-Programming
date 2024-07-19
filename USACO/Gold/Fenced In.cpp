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
    DSU(int n) : e(n+1,-1){}

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

struct A{
    int u,v;
    ll w;
    bool operator < (const A &o) const{
        return w > o.w;
    }
};

int main() {
    setIO("fencedin");
    int a,b,n,m;cin >> a >> b >> n >> m;
    vector<int> ver,h;
    DSU dsu((n+1)*(m+1));
    ver.push_back(0),h.push_back(0);
    ver.push_back(a),h.push_back(b);
    for(int i = 0;i < n;i++){
        int x;cin >> x;
        ver.push_back(x);
    }
    for(int i = 0;i < m;i++){
        int x;cin >> x;
        h.push_back(x);
    }
    sort(all(ver));
    sort(all(h));
    auto node = [&](int i,int j){
        return (j - 1) * (n + 1)+ i;
    };
    vector<A> fence;
    for(int i = 1;i<=n+1;i++){
        for(int j = 1;j<=m+1;j++){
            ll width = ver[i] - ver[i - 1];
            ll height = h[j] - h[j - 1];
            int u = node(i,j),v;
            if(i > 1){
                v = node(i - 1,j);
                fence.push_back({u,v,height});
            }
            if(j > 1){
                v = node(i,j - 1);
                fence.push_back({u,v,width});
            }
        }
    }
    sort(all(fence));
    reverse(all(fence));
    ll ans = 0;
    int cnt = 0;
    for(auto [u,v,w]:fence){
        if(!dsu.unite(u,v)) continue;
        ans += w;
    }
    cout << ans;
    return 0;
}
