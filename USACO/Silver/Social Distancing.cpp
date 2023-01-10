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
#define ld long double

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
ll n,m;
vector<pair<ll,ll>> grs;
ll check(ll mid){
    ll now=grs[0].first,p = 0,cnt = 0;
    while(now+mid < grs[m-1].second){
        while(now+mid > grs[p].second){
            p++;
        }
        now = max(now+mid,grs[p].first);
        cnt++;
    }
    return cnt+1;
}
int main() {
    setIO("socdist");
    cin >> n >> m;
    grs.resize(m);
    for(auto &[x,y]:grs) cin >> x >> y;
    sort(all(grs));
    ll l = 1,r = 1e18;
    while(l < r){
        ll mid = (l+r+1)>>1;
        if(check(mid) < n){
            r = mid-1;
        }
        else l = mid;
    }
    cout << l;
    return 0; 
}
