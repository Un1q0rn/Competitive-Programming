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
    setIO("");
    int n;cin >> n;
    vector<pair<int,char>> cows(n);
    for(auto &e:cows){
        cin >> e.second >> e.first ;
    }
    sort(all(cows));
    vector<int> lying_l(n),lying_r(n);
    for(int i=1;i<n;i++){
        lying_l[i]+=lying_l[i-1];
        if(cows[i-1].second == 'G') continue;
        if(cows[i].first > cows[i-1].first) lying_l[i]++;
    }
    for(int i=n-2;i>=0;i--){
        lying_r[i]+=lying_r[i+1];
        if(cows[i+1].second == 'L') continue;
        if(cows[i].first < cows[i+1].first) lying_r[i]++;
    }
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        ans = min(ans,lying_l[i]+lying_r[i]);
    }
    cout << ans << '\n';
    return 0;
}
