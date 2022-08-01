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
const int N = 4e3+20;
int a[N][N];
int main() {
    setIO("mowing");
    int n;cin >> n;
    int ni=2000,nj=2000;
    int now = 1,ans = 1e9;
    FOR(i,1,n){
        char s;cin >> s;
        int d;cin >> d;
        int di,dj;
        if(s == 'N'){
            di = -1;
            dj = 0;
        }
        else if(s == 'S'){
            di = 1;
            dj = 0;
        }
        else if(s == 'E'){
            di = 0;
            dj = 1;
        }
        else{
            di = 0;
            dj = -1;
        }
        d+=now;
        while(now<d){
            ni+=di;
            nj+=dj;
            if(a[ni][nj]){
                ans = min(ans,now-a[ni][nj]);
            }
            a[ni][nj] = now;
            now++;
        }
    }
    cout << (ans == 1e9 ? -1:ans);
    return 0;
}
