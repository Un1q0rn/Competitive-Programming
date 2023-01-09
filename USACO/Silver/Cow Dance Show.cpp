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
int n,t;
vector<int> a;
int check(int mid){
    int use = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    int p = 0;
    while(p < n && sz(pq) < mid){
        pq.push(a[p]);
        p++;
    }
    while(sz(pq)){
        use+=max(0,pq.top()-use);
        pq.pop();
        if(p < n){
            pq.push(a[p]+use);
            p++;
        }
    }
    return use;
}
int main() {
    setIO("cowdance");
    cin >> n >> t;
    a.resize(n);
    for(auto &e:a) cin >> e;
    int lo = 1,hi = n;
    while(lo < hi){
        int mid = lo+(hi-lo)/2;
        if(check(mid) <= t){
            hi = mid;
        }
        else {
            lo = mid+1;
        }
    }
    cout << hi;
    return 0; 
}
