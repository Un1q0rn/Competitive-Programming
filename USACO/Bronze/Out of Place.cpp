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
    setIO("outofplace");
    int n;cin >> n;
    vector<int> a(n);
    for(auto &e:a) cin >> e;
    a.resize(unique(all(a))-a.begin()) ;
    vector<int> b(a);
    sort(all(b));
    int cnt = 0;
    for(int i=0;i<sz(a);i++){
        cnt+=(a[i] != b[i]);
    }
    cout << cnt-1 ;
    return 0;
}
