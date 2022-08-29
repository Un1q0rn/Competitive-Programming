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
const int N = 1e3+10;
int a[N][N];
int main() {
    setIO("paintbarn");
    int n,k;cin >> n >> k;
    FOR(i,1,n){
        int x1,y1,x2,y2;cin >> x1 >> y1 >> x2 >> y2;
        x1++;y1++;
        a[x1][y1]++;
        a[x2+1][y1]--;
        a[x1][y2+1]--;
        a[x2+1][y2+1]++;
    }
    int ans = 0;
    FOR(i,1,N-1){
        FOR(j,1,N-1){
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            ans+=(a[i][j] == k);
        }
    }
    cout << ans;
    return 0;
}
