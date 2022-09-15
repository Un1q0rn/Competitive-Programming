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
    ll n,m,t;cin >> n >> m >> t;
    vector<ll> a(n-1);
    map<ll,ll> room;
    for(auto &e:a) cin >> e;
    while(m--){
        ll x,ti;cin >> x >> ti;
        room[x] = ti;
    }
    ll cur = 0;
    while(cur < n && t > 0){
        t+=room[cur+1]; 
        if(cur == n-1){
            cout << "Yes";
            return;
        }
        t-=a[cur];
        cur++;
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
