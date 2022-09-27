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

int a[12][12],n;
bool check(){
    bool res = true;
    FOR(i,1,n){
        FOR(j,1,n){
            res &= (a[i][j] == 0);
        }
    }
    return res;
}
int main() {
    setIO("cowtip");
    cin >> n;
    FOR(i,1,n){
        FOR(j,1,n){
            char x;cin >> x;
            a[i][j] = x-'0';
        }
    }
    int cnt = 0;
    while(!check()){
        pair<int,int> pos;
        FOR(i,1,n){
            FOR(j,1,n){
                if(a[i][j] == 1) pos = {i,j};
            }
        }
        FOR(i,1,pos.f){
            FOR(j,1,pos.s){
                a[i][j]^=1;
            }
        }
        cnt++;
    }
    cout << cnt;
    return 0;
}
