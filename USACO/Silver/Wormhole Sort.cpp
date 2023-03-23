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
    vector<int> pa;
    int n;
    DSU(int n){
        pa.resize(n);
        iota(all(pa),0);
    }
    int root(int x) {return (pa[x] == x ? x:pa[x] = root(pa[x]));}
    bool unite(int a,int b){
        a = root(a),b = root(b);
        if(a == b) return false;
        pa[a] = b;
        return true;
    }
};
struct A{
    int u,v,w;
    bool operator < (const A&o) const{
        return w > o.w;
    }
};
int main() {
    //Use SetIO function is grading forever for some reasons
    cin.tie(0)->sync_with_stdio(0);
    freopen("wormsort.in","r", stdin);
    freopen("wormsort.out","w", stdout);
    int n,m;cin >> n >> m;
    vector<int> a(n+1);
    vector<A> edge(m);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    sort(all(edge));
    int check = 1;
    for(int i=1;i<=n;i++) {
        if(a[i] != i) check = 0;
    }
    if(check){
        cout << -1;
        return 0;
    }
    int l = 1,r = 1e9;
    while(l<r){
        int mid = l+((r-l+1)>>1);
        DSU dsu(n+1);
        for(int i=0;i<m;i++){
            if(edge[i].w < mid) break;
            int u = edge[i].u,v = edge[i].v;
            dsu.unite(u,v);
        }
        int ok=1;
        for(int i=1;i<=n;i++){
            if(dsu.root(a[i]) != dsu.root(i)){
                ok = 0;
                break;
            }
        }
        if(ok){
            l = mid;
        }
        else{
            r = mid-1;
        }
    }
    cout << l;
    return 0;
}
