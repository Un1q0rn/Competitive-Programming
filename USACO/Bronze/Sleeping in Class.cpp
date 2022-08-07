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

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
void solve(){
    int n;cin >> n;
    vi(int) a(n);
    FOR(i,0,n-1){
        cin >> a[i];
        if(i){
            a[i]+=a[i-1];
        }
    }
    vi(int) fac;
    for(int i=1;i*i <= a[n-1];i++){
        if(!( a[n-1]%i )){
            fac.pb(i);
            if(a[n-1]/i != i) fac.pb(a[n-1]/i);
        }
    }
    int ans = 1e9;
    for(auto e:fac){
        int cnt = 0,last = -1,ch = 1;
        FOR(i,0,n-1){
            if(a[i] - (last == -1 ? 0:a[last]) == e){
                cnt+=(last == -1 ? i:i-last-1);
                last = i;
            }
            else if(a[i] - (last == -1 ? 0:a[last]) > e){
                ch = 0;
                break;
            }
        }
        if(ch) ans = min(ans,cnt);
    }
    cout << (ans == 1e9 ? 0:ans) << '\n';
}

int main() {
    setIO("");
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
