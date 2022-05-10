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
    setIO("div7");
    int n;cin >> n;
    vi(int) a(n+2),mod(7,-1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i]+=a[i-1];
        a[i]%=7;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(mod[a[i]] == -1){
            mod[a[i]] = i;
        }
        else{
            ans = max(ans,i-mod[a[i]]);
        }
    }
    cout << ans;
    return 0;
}
