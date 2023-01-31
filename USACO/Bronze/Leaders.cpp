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
    int n;cin >> n;
    string s;cin >> s;
    s = " "+s;
    vector<int> g(n+1),h(n+1),a(n+1);
    int tg=0,th=0;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        g[i]+=g[i-1]+(s[i] == 'G');
        h[i]+=h[i-1]+(s[i] == 'H');
        tg+=(s[i] == 'G');
        th+=(s[i] == 'H');
    }
    int gp=-1,hp=-1;
    for(int i=1;i<=n;i++){
        if(g[a[i]]-g[i-1] == tg) gp = i;
        if(h[a[i]]-h[i-1] == th) hp = i;
    }
    int ans = (gp != -1 && hp != -1);
    for(int i=1;i<=n;i++){
        if(s[i] == 'G'){
            ans+=(a[i] >= hp && i < hp);
        }
        if(s[i] == 'H'){
            ans+=(a[i] >= gp && i < gp);
        }
    }
    cout << ans;
    return 0; 
}
