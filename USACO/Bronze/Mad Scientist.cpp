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
    setIO("breedflip");
    ll n,ans=0;cin >> n;
    string a,b;cin >> a >> b;
    bool ch = false;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            if(!ch){
                ch = true;
                ans++;
            }
        }
        else{
            ch = false;
        }
    }
    cout << ans ;
    return 0;
}
