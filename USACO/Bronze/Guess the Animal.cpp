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
    setIO("guess");
    int n;cin >> n;
    set<string> a[n];
    FOR(i,0,n-1){
        string s;cin >> s;
        int k;cin >> k;
        while(k--){
            string t;cin >> t;
            a[i].insert(t);
        }
    }
    int ans = 0;
    FOR(i,0,n-1){
        FOR(j,i+1,n-1){
            int cnt=0;
            for(auto t:a[i]){
                if(a[j].find(t) != a[j].end()){
                    cnt++;
                }
            }
            ans = max(ans,cnt);
        }
    }
    cout << ans+1;
    return 0;
}
