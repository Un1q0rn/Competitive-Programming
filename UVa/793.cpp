#include <bits/stdc++.h> 
using namespace std; 
#define ull unsigned long long int
#define ll long long int 
#define ld long double
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,b,a) for(int i=b;i>=a;i--)
#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define setdecimal(x) cout << fixed << setprecision(x)
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
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
    int get(int i) {return (pa[i] == i ? i:pa[i] = get(pa[i]));}
    bool same(int a,int b) {return get(a) == get(b);}
    bool unite(int a,int b){
        a = get(a),b = get(b);
        if(a == b) return false;
        pa[a] = b;
        return true;
    }
};
void solve(){
    int n;cin >> n;
    DSU dsu(n+1);
    cin.ignore();
    int ans1=0,ans2=0;
    string s;
    while(getline(cin,s)){
        if(!sz(s)) break;
        char opr;
        int x,y;
        stringstream sr(s);
        sr >> opr;sr >> x;sr >> y;
        if(opr == 'c'){
            dsu.unite(x,y);
        }
        else if(opr == 'q'){
            if(dsu.same(x,y)){
                ans1++;
            }
            else ans2++;
        }
    }
    cout << ans1 << ',' << ans2 << '\n';
}

bool multi = true;

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

