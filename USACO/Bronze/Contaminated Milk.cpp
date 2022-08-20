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
int main() {
    setIO("badmilk");
    int n,m,d,s;cin >> n >> m >> d >> s;
    vi(vi(int)) fdt(m+1,vi(int)(n+1,101));
    FOR(i,1,d){
        int p,m,t;cin >> p >> m >> t;
        fdt[m][p] = min(fdt[m][p],t);
    }
    vi(int) sick(n+1,101);
    FOR(i,1,s){
        int p,t;cin >> p >> t;
        sick[p] = t;
    }
    int ans = 0;
    FOR(i,1,m){
        int ok = false;
        FOR(j,1,n){
            if(sick[j] < 101 && fdt[i][j] >= sick[j]){
                ok = true;
            }
        }
        if(!ok){
            int cnt = 0;
            FOR(j,1,n){
                if(fdt[i][j] < 101){
                    cnt++;
                }
            }
            ans = max(ans,cnt);
        } 
    }
    cout << ans;
    return 0;
}
