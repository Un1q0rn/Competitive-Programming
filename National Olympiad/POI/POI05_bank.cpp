#include <bits/stdc++.h> 
using namespace std; 
 
#define ll long long int 
#define ld long double
#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
struct DSU{
    vector<int> pa;
    DSU(int n){
        pa.resize(n);
        iota(all(pa),0);
    }
    int root(int x){return (pa[x] == x ? x:pa[x] = root(pa[x]));}
    bool unite(int a,int b){
        a = root(a),b = root(b);
        if(b == a) return false;
        pa[a] = b;
        return true;
    }
};
int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int n;cin >> n;
    DSU dsu(n+1);
    int ans = 0;
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        if(!dsu.unite(i,x)){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
