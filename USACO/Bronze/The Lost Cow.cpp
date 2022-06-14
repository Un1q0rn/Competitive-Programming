#include <bits/stdc++.h>
using namespace std;

#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

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
    setIO("lostcow");
    int x,y;cin >> x >> y;
    ll dir=1,now=1,ans=0;
    while(1){
        if((dir == 1 && x+now>=y && y>=x) || (dir == -1 && x-now<=y && y<=x)){
            ans+=abs(x-y);
            cout << ans;
            break;
        }
        else{
            now*=2;
            ans+=now;
            dir*=-1;
        }
    }
    return 0;
}
