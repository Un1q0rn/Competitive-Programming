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
    setIO("shuffle");
    int n;cin >> n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        m[i] = x-1;
    }
    for(int i=0;i<n;i++){
        int x;cin >> x;
        a.pb(x);
    }
    int t = 3;
    while(t--){
        vector<int> tmp;
        for(int i=0;i<n;i++){
            tmp.pb(a[m[i]]);
        }
        a = tmp;
    }
    for(auto e:a) cout << e << '\n';
    return 0;
}
