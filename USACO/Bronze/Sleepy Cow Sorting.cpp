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
    setIO("sleepy");
    int n;cin >> n;
    vi(int) a(n);
    for(auto &e:a) cin >> e;
    int cnt = 0;
    while(!is_sorted(all(a))){
        for(int i=1;i<n && !is_sorted(a.begin()+i-1,a.end());i++){
            swap(a[i],a[i-1]);
        }
        cnt++;
    }
    cout << cnt;
    return 0;
}
