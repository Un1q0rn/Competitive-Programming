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
    setIO("cardgame");
    int n;cin >> n;
    vector<int> a1,a2,b1,b2,mark(2*n+1);
    for(int i=0;i<n;i++){
        int x;cin >> x;
        if(sz(b1) < n/2){
            b1.pb(x);
        }
        else b2.pb(x);
        mark[x] = 1;
    }
    sort(all(b1));
    sort(all(b2),greater<int>());
    for(int i=1;i<=2*n;i++){
        if(mark[i]) continue;
        if(sz(a2) < n/2){
            a2.pb(i);
        }
        else{
            a1.pb(i);
        }
    }
    reverse(all(a2));
    int p1=0,p2=0,ans=0;
    while(p1 < sz(a1)){
        if(a1[p1] > b1[p2]){
            ans++;
            p2++;
        }
        p1++;
    }
    p1 = 0,p2 = 0;
    while(p1 < sz(a2)){
        if(a2[p1] < b2[p2]){
            ans++;
            p2++;
        }
        p1++;
    }
    cout << ans;
    return 0;
}

