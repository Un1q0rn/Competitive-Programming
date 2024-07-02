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
    setIO("berries");
    int n,k;cin >> n >> k;
    vector<int> a(n);
    int mx = 0;
    for(auto &e:a) {
        cin >> e;
        mx = max(mx,e);
    }
    int ans = 0;
    for(int i=1;i<=mx;i++){
        int now = 0;
        for(int j=0;j<n;j++){
            now += a[j]/i;
        }
        if(now < k/2) break;
        if(now >= k){
            ans = max(ans,i * (k/2));
            continue;
        }
        vector<int> mod;
        for(int j=0;j<n;j++){
            mod.push_back(a[j]%i);
        }
        sort(all(mod),greater<int>());
        int bes = i * (now - k/2);
        for(int j=0;j<n && j+now < k;j++){
            bes += mod[j];
        }
        ans = max(ans,bes);
    }
    cout << ans;
    return 0;
}
