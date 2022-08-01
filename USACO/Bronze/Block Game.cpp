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
    setIO("blocks");
    int n;cin >> n;
    vector<int> cnt(26);
    FOR(i,1,n){
        map<char,int>  word,m1,m2;
        string s,t;cin >> s >> t;
        for(auto c:s){
            m1[c]++;
            word[c]=1;
        }
        for(auto c:t){
            m2[c]++;
            word[c]=1;
        }
        for(auto m:word){
            cnt[m.first-'a']+=(max(m1[m.first],m2[m.first]));
        }
    }
    for(auto e:cnt) cout << e << '\n';
    return 0;
}
