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
    setIO("cbarn");
    int n;cin >> n;
    vi(int) a(n);
    for(auto &e:a){
        cin >> e;
    }
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=1;j<n;j++){
            sum+=a[(i+j)%n]*j;;
        }
        ans = min(ans,sum);
    }
    cout << ans << endl;
    return 0;
}
