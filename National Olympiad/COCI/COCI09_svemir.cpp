#include <bits/stdc++.h> 
using namespace std;

#define vi(x)  vector<x>
#define pb push_back
#define pf push_front
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,b,a) for(int i=b;i>=a;i--)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define setdecimal(x) cout << fixed << setprecision(x)

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
#define ll long long 

const int N = 1e6+100; 
struct DSU{
    vector<int> pa;
    int n;
    DSU(int n){
        pa.resize(n);
        iota(all(pa),0);
    }
    int root(int i) {return pa[i] == i ? i:pa[i] = root(pa[i]);}
    bool same(int x,int y) {return root(x) == root(y);}
    bool unite(int x,int y){
        x = root(x),y = root(y);
        if(x == y) return false;
        pa[x] = pa[y];
        return true;
    }
};

struct edge{
    int u,v,w;
    bool operator < (const edge&o) const{
        return w>o.w;
    }
};

struct planet{
    int x,y,z,idx;

    bool operator < (const planet&o) const{
        if(x != o.x) return x < o.x;
        if(y != o.y) return y < o.y;
        if(z != o.z) return z < o.z;
        return false;
    }
};

int dist(const planet &A,const planet &B){
    return min({abs(A.x-B.x),abs(A.y-B.y),abs(A.z-B.z)});
}

priority_queue<edge> pq;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    vector<planet> a;
    for(int i=0;i<n;i++){
        int x,y,z;cin >> x >> y >> z;
        a.pb({x,y,z,i});
    }

    sort(all(a),[&](const planet &A,const planet &B){return A.x < B.x;});
    for(int i=0;i<n-1;i++){
        pq.push({a[i].idx,a[i+1].idx,dist(a[i],a[i+1])});
    }

    sort(all(a),[&](const planet &A,const planet &B){return A.y < B.y;});
    for(int i=0;i<n-1;i++){
        pq.push({a[i].idx,a[i+1].idx,dist(a[i],a[i+1])});
    }

    sort(all(a),[&](const planet &A,const planet &B){return A.z < B.z;});
    for(int i=0;i<n-1;i++){
        pq.push({a[i].idx,a[i+1].idx,dist(a[i],a[i+1])});
    }

    ll ans = 0;
    DSU dsu(n+1);
    while(sz(pq)){
        int u = pq.top().u,v = pq.top().v,w = pq.top().w;
        pq.pop();
        if(dsu.unite(u,v)){
            ans+=w;
        }
    }

    cout << ans;
    return 0;
}
