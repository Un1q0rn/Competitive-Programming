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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    vector<int> a,ps;
    vector<pi> upd;
    for(int i=0;i<n;i++){
        int l,r;cin >> l >> r;
        a.pb(l);a.pb(r);
        upd.pb({l,r});
    }
    sort(all(a));
    ps.resize(sz(a)+1);
    for(int i=0;i<n;i++){
        auto now = upd[i];
        ps[lower_bound(all(a),now.first)-a.begin()]++;
        ps[lower_bound(all(a),now.second)-a.begin()]--;
    }
    int ans = 0;
    for(int i=1;i<sz(ps);i++){
        ps[i]+=ps[i-1];
        ans = max(ans,ps[i]);
    }
    cout << ans;
    return 0;
}
