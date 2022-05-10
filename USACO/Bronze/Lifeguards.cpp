#include <bits/stdc++.h>
using namespace std;

#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

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

map<int,int> m;
int main() {
    setIO("lifeguards");
    int n;cin >> n;
    vi(pi) t;
    for(int i=0;i<n;i++){
        int l,r;cin >> l >> r;
        m[l]++,m[r]--;
        t.pb({l,r});
    }
    int ans = 0;
    for(auto e:t){
        int l = e.f,r = e.s;
        m[l]--,m[r]++;
        int now=0,last=0,cnt = 0;
        for(auto x:m){
            if(now > 0) cnt+=x.f-last;
            now += x.s;
            last = x.f;
        }
        ans = max(ans,cnt);
        m[l]++,m[r]--;
    }
    cout << ans;
    return 0;
}
