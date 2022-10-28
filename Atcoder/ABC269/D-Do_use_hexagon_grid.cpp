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
int dx[6]{-1,-1,0,0,0,0},dy[6]{-1,0,-1,1,0,1};
struct DSU{
    vector<int> pa;
    int n;
    DSU(int n){
        pa.resize(n);
        iota(all(pa),0);
    }
    int root(int i){return pa[i] == i ? i:pa[i] = root(pa[i]);}
    bool same(int a,int b){return root(a) == root(b);}
    bool unite(int a,int b){
        a = root(a),b = root(b);
        if(a == b) return false;
        pa[a] = b;
        return true;
    }
};
int mem[2010][2010],x[1010],y[1010];

void solve(){
    int n;cin >> n;
    for(int i=1;i<=n;i++){
        cin >> x[i] >> y[i];
        x[i]+=1005,y[i]+=1005;
        mem[x[i]][y[i]] = i;
    }
    DSU dsu(n+1);
    for(int i=1;i<=n;i++){
        for(int k=0;k<6;k++){
            int xi = x[i]+dx[k];
            int yi = y[i]+dy[k];
            if(mem[xi][yi]){
                dsu.unite(i,mem[xi][yi]);
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) ans+=(dsu.root(mem[x[i]][y[i]]) == i);
    cout << ans;
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
