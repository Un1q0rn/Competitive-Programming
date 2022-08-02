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
struct Cow{
    int d;
    string name;
    int x;
    bool operator < (const Cow & o) const{
        return d < o.d;
    }
};
int main() {
    setIO("measurement");
    int n;cin >> n;
    vector<Cow> a;
    FOR(i,1,n){
        int d,x;
        string s;
        cin >> d >> s >> x;
        a.pb({d,s,x});
    }
    sort(all(a));
    map<string,int> m;
    vector<int> board(3,1);
    int mx = 0,ans = 0;
    int now = 0;
    FOR(i,1,100){
        m["Bessie"]+=7;
        m["Elsie"]+=7;
        m["Mildred"]+=7;
        if(now < n && i == a[now].d){
            m[a[now].name]+=a[now].x;
            now++;
        }
        mx = max({m["Bessie"],m["Elsie"],m["Mildred"]});
        vector<int> boardnow(3,1);
        if(m["Bessie"] == mx){
            boardnow[0] = 1;
        }
        else boardnow[0] = 0;
        if(m["Elsie"] == mx){
            boardnow[1] = 1;
        }
        else boardnow[1] =0;
        if(m["Mildred"] == mx){
            boardnow[2] = 1;
        }
        else boardnow[2] = 0;
        if(board != boardnow){
            ans++;
        }
        board = boardnow;
    }
    cout << ans;
    return 0;
}
