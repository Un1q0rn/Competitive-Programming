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
    cin.tie(0)->sync_with_stdio(0);
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
int main() {
    setIO("helpcross");
    int c,n;cin >> c >> n;
    multiset<int> chick;
    vector<pair<int,int>> cows(n);
    for(int i=0;i<c;i++){
        int x;cin >> x;
        chick.insert(x);
    }
    for(int i=0;i<n;i++){
        cin >> cows[i].f >> cows[i].s;
    }
    sort(all(cows),[](auto a,auto b){
            if(a.s != b.s) return a.s < b.s;
            return a.f < b.f;
    });
    int ans = 0;
    for(auto [l,r]:cows){
        auto it = chick.lower_bound(l);
        if(it != chick.end() && *it <= r){
            ans++;
            chick.erase(it);
        }
    }
    cout << ans;
    return 0;
}
