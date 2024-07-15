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

ll dist(pair<int,int> a,pair<int,int> b){
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

struct A{
    int u,v;
    ll w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};

int main() {
    setIO("moocast");
    int n;cin >> n;
    DSU dsu(n);
    vector<pair<int,int>> a(n);
    for(auto &[x,y]:a){
        cin >> x >> y;
    }
    priority_queue<A> pq;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            pq.push({i,j,dist(a[i],a[j])});
        }
    }
    ll ans = 0;
    while(sz(pq)){
        int u = pq.top().u;
        int v = pq.top().v;
        ll w = pq.top().w;
        pq.pop();
        if(!dsu.unite(u,v)) continue;
        ans = max(ans,w);
    }
    cout << ans;
    return 0;
}
