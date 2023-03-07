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
struct note{
    int day,idx,change;
    bool operator < (const note&o) const{
        return day < o.day;
    }
};
int main() {
    setIO("measurement");
    int n,g;cin >> n >> g;
    vector<note> a(n);
    for(auto &[day,idx,change]:a){
        cin >> day >> idx >> change;
    }
    sort(all(a));
    map<int,int,greater<int>> milk;
    map<int,int> cows;
    int ans = 0;
    milk[0] = n;
    for(auto [day,idx,change]:a){
        int prevmilk = cows[idx];
        int prevtop = (prevmilk == milk.begin()->first);
        int prevcnt = milk[prevmilk];
        milk[prevmilk]--;
        if(!milk[prevmilk]){
            milk.erase(prevmilk);
        }
        int nowmilk = prevmilk+change;
        milk[nowmilk]++;
        cows[idx] = nowmilk;
        int nowtop = (nowmilk == milk.begin()->first);
        int nowcnt = milk[nowmilk];
        if(prevtop){
            if(nowtop && nowcnt == prevcnt) continue;
            ans++;
        }
        else if(nowtop){
            ans++;
        }
    }
    cout << ans;
    return 0;
}

