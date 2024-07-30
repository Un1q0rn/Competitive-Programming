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
    vector<int> e,mx;
    DSU(int n) : e(n, -1),mx(n){}

    int root(int i) {return e[i] < 0 ? i : e[i] = root(e[i]);}
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
    int u,v,w;
    bool operator < (const A & o) const{
        return w < o.w;
    }
};

int main() {
    setIO("tractor");
    int n;cin >> n;
    DSU dsu(n * n + 1);
    vector<vector<int>> a(n + 1,vector<int>(n + 1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    vector<A> edges;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=-1;k<=1;k++) for(int l=-1;l<=1;l++){
                if(abs(k) == abs(l)) continue;
                int ii = i + k,jj = j + l;
                if(ii < 1 || ii > n || jj < 1 || jj > n) continue;
                if(a[ii][jj] < a[i][j]) continue;
                edges.push_back({(i - 1) * n + j,(ii - 1) * n + jj,a[ii][jj] - a[i][j]});
            }
        }
    }
    sort(all(edges));
    int ans = 0;
    for(auto [u,v,w]:edges){
        if(!dsu.unite(u,v)) continue;
        ans = max(ans,w);
        if(dsu.size(u) >= (n * n) / 2) break;
    }
    cout << ans;
    return 0;
}
