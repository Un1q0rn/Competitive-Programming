#include <bits/stdc++.h> 
using namespace std; 
#define ull unsigned long long int
#define ll long long int 
#define ld long double
#define FOR(a,b) for(int i=a;i<=b;i++)
#define vi(x)  vector<x>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define setdecimal(x) cout << fixed << setprecision(x)
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
#define ll long long int
const int MOD = 1e9+7;
ll gcd(ll a,ll b){
    if(!(a%b)) return b;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
struct DSU{
    vector<int> pa;
    DSU(int n){
        pa.resize(n);
        iota(all(pa),0);
    }
    int root(int i){return (pa[i] == i ? i:pa[i] = root(pa[i]));}
    bool same(int x,int y) { return root(x)==root(y); }
    bool unite(int x,int y){
        x = root(x),y = root(y);
        if(x == y) return false;
        pa[x] = y;
        return true;
    }
};
struct A{
    int u,v,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
int dist(pi a,pi b){
    return (a.f-b.f)*(a.f-b.f)+(a.s-b.s)*(a.s-b.s);
}
int t;
priority_queue<A> pq;
void solve(){
    int n;cin >> n;
    vector<pi> town(n+1);
    DSU dsu(n+1);
    for(int i=1;i<=n;i++){
        cin >> town[i].f >> town[i].s;
    }
    int m;cin >> m;
    while(m--){
        int u,v;cin >> u >> v;
        dsu.unite(u,v);
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            pq.push({i,j,dist(town[i],town[j])});
        }
    }
    bool ch = false;
    while(sz(pq)){
        int u = pq.top().u,v = pq.top().v;
        pq.pop();
        if(dsu.same(u,v)) continue; 
        ch = true;
        dsu.unite(u,v);
        cout << u << ' ' << v << '\n';
    }
    if(!ch) cout << "No new highways need\n";
    if(t)cout << '\n';
} 

int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    cin >> t;
    //t = 1;
    while(t--){
        solve();
    }
    return 0;
}
