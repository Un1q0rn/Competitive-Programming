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
struct cow{
    int t,idx,is_st;
    bool operator < (const cow&o) const{
        return t < o.t;
    }
};
int main() {
    setIO("lifeguards");
    int n;cin >> n;
    vector<cow> event;
    for(int i=0;i<n;i++){
        int l,r;cin >> l >> r;
        event.pb({l,i,1});
        event.pb({r,i,0});
    }
    sort(all(event));
    vector<int> a(n);
    set<int> working;
    int prev = 0,total = 0;
    for(auto &e:event){
        ll now = e.t;
        if(sz(working) > 0){
            total += now - prev;
        }
        if(sz(working) == 1){
            a[*working.begin()] += now-prev;
        }
        if(e.is_st){
            working.insert(e.idx);
        }
        else working.erase(e.idx);
        prev = now;
    }
    int min_time = *min_element(all(a));
    cout << total-min_time;
    return 0;
}
