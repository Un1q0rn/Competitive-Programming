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

int main() {
    setIO("diamond");
    int n,k;cin >> n >> k;
    vector<int> a(n);
    for(auto &e:a) cin >> e;
    sort(all(a));
    int ans = 0;
    for(int i=0;i<n;i++){
        int cnt = 1;
        for(int j=i+1;;j++){
            if(j>n-1) break;
            if(a[j]-a[i] > k) break;
            cnt++;
        }
        ans = max(cnt,ans);
    }
    cout << ans << '\n';
    return 0;
}
