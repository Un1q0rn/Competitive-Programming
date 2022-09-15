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
    if(!(a%b)) return b;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
void solve(){
    ll n,p,q,r;cin >> n >> p >> q >> r;
    vector<ll> a(n),pref(n+1);
    for(auto &e:a) cin >> e;
    FOR(i,1,n){
        pref[i] += a[i-1]+pref[i-1];
    }
    auto b_search = [&](ll key){
        int l = 1,r = n;
        while(l <= r){
            int mid = (l+r)>>1;
            if(pref[mid] == key){
                return true;
            }
            else if(pref[mid] < key){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return false;
    };
    FOR(i,0,n){
        ll x = pref[i];
        if(b_search(x+p) && b_search(x+p+q) && b_search(x+p+q+r)){
            cout << "Yes";
            return ;
        }
    }
    cout << "No";
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
