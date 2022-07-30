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
    setIO("angry");
    int n;cin >> n;
    vector<int> a(n);
    for(auto &e:a) cin >> e;
    sort(all(a));
    int ans = 0;
    FOR(i,0,n-1){
        int now = i;
        int radi = 1,cnt = 0;
        while(now > 0){
            int l = now-1;
            if(a[now]-a[l] <= radi){
                while(l >= 0 && a[now]-a[l] <= radi){
                    cnt++;
                    l--;
                }
            }
            else break;
            now = l+1;
            radi++;
        }
        now = i;
        radi = 1;
        while(now < n-1){
            int r = now+1;
            if(a[r]-a[now] <= radi){
                while(r <= n-1 && a[r]-a[now] <= radi) {
                    cnt++;
                    r++;
                }
            }
            else break;
            now = r-1;
            radi++;
        }
        ans = max(ans,cnt+1);
    }
    cout << ans;
    return 0;
}
