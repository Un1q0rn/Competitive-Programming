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
const int N = 2500+10;
pi p[N];
int psum[N][N],n;
int rsum(int x1,int y1,int x2,int y2){
    return psum[x2+1][y2+1]-psum[x2+1][y1]-psum[x1][y2+1]+psum[x1][y1];
}

int main() {
    setIO("");
    cin >> n;
    for(int i=0;i<n;i++){
        int x,y;cin >> x >> y;
        p[i] = {x,y};
    }
    sort(p,p+n,[&](const pi&a,const pi&b){return a.first < b.first;});
    for(int i=0;i<n;i++){
        p[i].first = i+1;
    }
    sort(p,p+n,[&](const pi&a,const pi&b){return a.second < b.second;});
    for(int i=0;i<n;i++){
        p[i].second = i+1;
    }
    for(int i=0;i<n;i++){
        psum[p[i].first][p[i].second]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            psum[i][j]+=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1];
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int x1 = min(p[i].first,p[j].first)-1;
            int x2 = max(p[i].first,p[j].first)-1;
            ans+= rsum(0,i,x1,j)*rsum(x2,i,n-1,j);
        }
    }
    cout << ans+1;
    return 0;
}
