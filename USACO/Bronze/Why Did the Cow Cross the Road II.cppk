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
    setIO("circlecross");
    string s;cin >> s;
    map<char,int> cnt;
    int ans = 0;
    for(int i=0;i<sz(s);i++){
        map<char,int> cnt2;
        int j = i;
        while(cnt[s[i]] < 2){
            if(s[j] == s[i]) cnt[s[i]]++;
            else{
                cnt2[s[j]]++;
            }
            j++;
        }
        for(auto e:cnt2){
            if(e.second == 1){
                if(cnt[e.first] < 2) ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
