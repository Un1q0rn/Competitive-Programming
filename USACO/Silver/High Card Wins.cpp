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
    setIO("highcard");
    int n;cin >> n;
    vector<int> mark(2*n+1),a,b;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        mark[x] = 1;
    }
    for(int i=1;i<=2*n;i++){
        if(mark[i]) b.pb(i);
        else a.pb(i);
    }
    sort(all(a));
    sort(all(b));
    int p1=0,p2=0;
    while(p1 < n){
        if(a[p1] > b[p2]){
            p2++;
        }
        p1++;
    }
    cout << p2;
    return 0;
}

