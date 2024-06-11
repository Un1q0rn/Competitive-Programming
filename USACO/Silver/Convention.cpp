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
    setIO("convention");
    int n,m,c;cin >> n >> m >> c;
    vector<int> a(n);
    for(auto &e:a) cin >> e;
    sort(all(a));
    int l = 0,r = 1e9;
    while(l < r){
        int mid = (l+r)>>1;
        int now = 0,cnt = 0,bus = 1;
        for(int i=0;i<n;i++){
            if(now == 0) now = a[i];
            if(a[i]-now <= mid){
                cnt++;
            }
            else{
                bus++;
                cnt = 1;
                now = a[i];
            }
            if(cnt == c){
                if(i != n-1){
                    bus++;
                    now = a[i+1];
                }
                cnt = 0;
            }
        }
        if(bus <= m){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    cout << r;
    return 0;
}
