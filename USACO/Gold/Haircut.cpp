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

struct BIT{
    vector<ll> f;
    BIT(int n) : f(n+2){}
    int n = sz(f) - 1;

    void upd(int i){
        i++;
        while(i <= n){
            f[i]++;
            i += i & -i;
        }
    }

    ll qry(int i){
        i++;
        ll res = 0;
        while(i > 0){
            res += f[i];
            i -= i & -i;
        }
        return res;
    }
};

int main() {
    setIO("haircut");
    int n;cin >> n;
    BIT fen1(n),fen2(n);
    vector<ll> a(n),inv_up(n+1),inv_down(n+1);
    for(auto &e:a){
        cin >> e;
        inv_down[e] += fen2.qry(n) - fen2.qry(e);
        fen2.upd(e);
    }
    for(int i = n-1;i >= 0;i--){
        inv_up[a[i]] += fen1.qry(a[i] - 1);
        fen1.upd(a[i]);
    }
    vector<ll> ans;
    ll res = accumulate(all(inv_up),0ll);
    for(int i=n-1;i>=0;i--){
        res -= inv_down[i];
        ans.push_back(res);
    }
    reverse(all(ans));
    for(auto e:ans) cout << e << '\n';
    return 0;
}
