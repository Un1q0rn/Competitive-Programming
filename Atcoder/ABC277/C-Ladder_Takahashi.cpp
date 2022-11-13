#include <bits/stdc++.h> 
using namespace std; 
#define ull unsigned long long int
#define ll long long int 
#define ld long double
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,b,a) for(int i=b;i>=a;i--)
#define vi(x)  vector<x>
#define pb push_back
#define pf push_front
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define setdecimal(x) cout << fixed << setprecision(x)
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
ll gcd(ll a,ll b){
    return b == 0 ? a:gcd(b,a%b);
}
struct DSU{
    vector<int> pa;
    int n;
    DSU(int n){
        pa.resize(n);
        iota(all(pa),0);
    }
    int root(int i){return (pa[i] == i ? i:pa[i] = root(pa[i]));}
    bool same(int a,int b) {return root(a) == root(b);}
    bool unite(int a,int b){
        a = root(a),b =root(b);
        if(a == b) return false;
        if(a > b) swap(a,b);
        pa[a] = b;
        return true;
    }
};
void solve(){
    int n;cin >> n;
    vector<int> a;
    vector<pi> ord;
    for(int i=0;i<n;i++){
        int u,v;cin >> u >> v;
        a.pb(u);a.pb(v);
        ord.pb({u,v});
    }
    a.pb(1);
    sort(all(a));
    a.erase(unique(all(a)),a.end());
    DSU dsu(sz(a)+1);
    for(int i=0;i<n;i++){
        int u = ord[i].first,v = ord[i].second;
        dsu.unite(lower_bound(all(a),u)-a.begin(),lower_bound(all(a),v)-a.begin());

    }
    int ans = dsu.root(dsu.pa[0]);
    cout << a[ans];
}

bool multi = false;

int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int t = 1;
    if(multi) cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
