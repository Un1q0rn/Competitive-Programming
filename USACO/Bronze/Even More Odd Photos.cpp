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
    int odd=0,even=0;
    FOR(i,1,n){
        int x;cin >> x;
        odd+=(x&1);
        even+=(x%2==0);
    }
    int cnt = 0;
    while((cnt%2 == 0 && (even > 0 || odd > 1)) || (cnt%2 == 1 && (odd > 0)) ){
        if(cnt%2 == 0){
            if(even > 0){
                even--;
            }
            else odd-=2;
        }
        else {
            odd--;
        }
        cnt++;
    }
    cout << (odd > 0 ? cnt-1:cnt);
    return 0;
}
