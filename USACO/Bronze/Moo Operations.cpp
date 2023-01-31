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
    //setIO("sleepy");
    int q;cin >> q;
    while(q--){
        string s;cin >> s;
        int ans = 1e9;
        for(int i=0;i<sz(s)-2;i++){
            if(s[i+1]!='O') continue;
            int cnt = 0;
            cnt += (s[i] != 'M')+(s[i+2]!='O');
            cnt += i+(sz(s)-i-3);
            ans = min(ans,cnt);
        }
        cout << (ans == 1e9 ? -1:ans) << '\n';
    }
    return 0;
}
