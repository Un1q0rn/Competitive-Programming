#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 
#define sz(x) (int)x.size()

struct DSU{
    vector<int> e;
    int cmpn;
    DSU(int n) {e = vector<int>(n,-1);cmpn = n;}
    int get(int i) {return (e[i] < 0 ? i:e[i] = get(e[i]));}
    bool same(int a,int b) {return get(a) == get(b);}
    int size(int i) {return -e[get(i)];}
    bool unite(int a,int b){
        a = get(a),b = get(b);
        if(a == b) return false;
        if(e[a] > e[b]) swap(a,b);
        e[a]+=e[b];e[b] = a;
        cmpn--;
        return true;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin >> n >> m;
    DSU dsu(n+1);
    int mx = 0;
    while(m--){
        int u,v;cin >> u >> v;
        dsu.unite(u,v);
        mx = max(mx,dsu.size(dsu.get(u)));
        cout << dsu.cmpn-1 << ' ' << mx << '\n';
    }
    return 0;
}
