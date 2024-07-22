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
    setIO("hps");
    int n,k;cin >> n >> k;
    vector<vector<int>> h,p,s;
    h = p = s = vector<vector<int>>(n + 1,vector<int>(k + 1));
    vector<char> c(n);
    for(auto &e:c) cin >> e;
    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++){
            h[i][j] = max((i ? h[i - 1][j] : 0),(i && j ? max(p[i - 1][j - 1],s[i - 1][j - 1]) : 0)) + (c[i] == 'H');
            p[i][j] = max((i ? p[i - 1][j] : 0),(i && j ? max(h[i - 1][j - 1],s[i - 1][j - 1]) : 0)) + (c[i] == 'P');
            s[i][j] = max((i ? s[i - 1][j] : 0),(i && j ? max(h[i - 1][j - 1],p[i - 1][j - 1]) : 0)) + (c[i] == 'S');
        }
    }
    cout << max({h[n - 1][k],p[n - 1][k],s[n - 1][k]});
    return 0;
}
