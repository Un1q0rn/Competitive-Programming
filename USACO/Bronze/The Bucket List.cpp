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
const int N = 1e3+10;
int a[N];
int main() {
    setIO("blist");
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int l,r,x;cin >> l >>r >> x;
        a[l] += x;
        a[r+1] += -x;
    }
    int ans = 0;
    for(int i=1;i<1010;i++){
        a[i]+=a[i-1];
        ans = max(a[i],ans);
    }
    cout << ans;
    return 0;
}
