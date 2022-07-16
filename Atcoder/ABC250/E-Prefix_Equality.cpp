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
void solve(){
    int n;cin >> n;
    vector<int> a(n+1),b(n+1),ma(n+1),mb(n+1);
    FOR(1,n) cin >> a[i];
    FOR(1,n) cin >> b[i];
    set<int> sa,sb;
    int ia=1,ib=1;
    while(ia <= n && ib <= n){
        sa.insert(a[ia]);
        ma[ia] = sz(sa);
        ia++;
        while(ia <= n && sa.find(a[ia]) != sa.end()){
            ma[ia] = sz(sa);
            ia++;
        }
        while(ib <= n && sa.find(b[ib]) != sa.end() && sz(sb) < sz(sa)){
            sb.insert(b[ib]);
            ib++;
        }
        if(sz(sa) == sz(sb)){
            mb[ib-1] = sz(sa);
            while(ib <= n && sb.find(b[ib]) != sb.end()){
                mb[ib] = sz(sa);
                ib++;
            }
        }
    }
    int q;cin >> q;
    while(q--){
        int x,y;cin >> x >> y;
        cout << (ma[x] == mb[y] ? "Yes":"No") << '\n';
    }
} 

int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    //int t;cin >> t;
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
