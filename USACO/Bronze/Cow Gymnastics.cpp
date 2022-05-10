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

int main() {
    setIO("gymnastics");
    int k,n;cin >> k >> n;
    vector<int> a[k];
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            int x;cin >> x;
            a[i].pb(x);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int cnti = 0,cntj = 0;
            for(int l=0;l<k;l++){
                for(auto x:a[l]){
                    if(x == i){
                        cnti++;
                        break;
                    }
                    if(x == j){
                        cntj++;
                        break;
                    }
                }
            }
            if(cnti == k || cntj == k) ans++;
        }
    }
    cout << ans;
    return 0;
}
