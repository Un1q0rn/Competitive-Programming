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
const int MOD = 998244353;
void solve(){
    int n,m;cin >> n >> m;
    vector<pair<int,int>> dir;
    FOR(i,1,3){
        int x,y;cin >> x >> y;
        dir.pb({x,y});
    }
    set<pair<int,int>> s;
    while(m--){
        int x,y;cin >> x >> y;
        s.insert({x,y});
    }
    map<pair<ll,ll>,int> dp;
    dp[{0,0}] = 1;
    FOR(i,0,n-1){
        map<pair<ll,ll>,int> new_dp;
        for(auto [xy,val]:dp){
            auto [x,y] = xy;
            for(auto [dx,dy]:dir){
                if(s.find({x+dx,y+dy}) == s.end()){
                    new_dp[{x+dx,y+dy}] += val;
                    new_dp[{x+dx,y+dy}] %= MOD;
                }
            }
        }
        swap(dp,new_dp);
    }
    int ans = 0;
    for(auto [_,val]:dp){
        ans+=val;
        ans%=MOD;
    }
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
