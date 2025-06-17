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

void solve(){
    int n,k;cin >> n >> k;
    vector<int> a(n);
    vector<tuple<int,int,int,int>> event(n + k);

    for(auto &e:a){
        cin >> e;
        event.push_back({e,1,0,0});
    }

    sort(all(a));

    for(int i=0;i<k;i++){
        int l,r,t;cin >> l >> r >> t;
        auto it_l = lower_bound(all(a),l);
        auto it_r = upper_bound(all(a),r);
        int all = distance(it_l,it_r);
        event.push_back({l,-1,r,all - t});
    }

    sort(all(event));
    ll ans = 0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;

    for(auto [pos,t,r,tree] : event){
        while(sz(pq) && pos > pq.top().second){
            pq.pop();
        }

        if(t == 1){
            if(!sz(pq) || ans < pq.top().first){
                ans++;
            }
        }
        else{
            pq.push({ans + tree,r});
        }
    }

    cout << ans << '\n';
}

int main() {
    setIO("");
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
