#include <bits/stdc++.h>
using namespace std;

#define vi(x)  vector<x>;
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
    setIO("mixmilk");
    vector<pair<int,int>> a(3);
    int now;
    for(auto &e:a){
        cin >> e.first >> e.second;
    }
    for(int i=0;i<100;i++){
        now = i%3;
        if(a[now].s+a[(now+1)%3].s <= a[(now+1)%3].f){
            a[(now+1)%3].s+=a[now].s;
            a[now].s = 0;
        }
        else{
            a[now].s -= a[(now+1)%3].f-a[(now+1)%3].s;
            a[(now+1)%3].s = a[(now+1)%3].f;
        }
    }
    for(auto e:a){
        cout << e.s << "\n";
    }
    return 0;
}
