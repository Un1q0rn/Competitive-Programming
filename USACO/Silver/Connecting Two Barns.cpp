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
    setIO("");
    int n,m;cin >> n >> m;
    vector<ll> a(2*m+2),li(m+1),ri(m+1);
    while(n--){
        int l,r;cin >> l >> r;
        li[l]++;
        ri[r]++;
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=m;j++){
            a[i+j]+=li[i]*li[j];
            a[i+j+1]-=ri[i]*ri[j];
        }
    }
    for(int i=1;i<=2*m;i++){
        a[i]+=a[i-1];
    }
    for(int i=0;i<=2*m;i++){
        cout << a[i] << '\n';
    }
    return 0;
}
