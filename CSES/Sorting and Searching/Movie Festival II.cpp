#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) begin(x),end(x)
#define pb push_back
#define sz(x) (int)x.size()
#define s second
#define f first
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,k;cin >> n >> k;
    multiset<int> s;
    for(int i=0;i<k;i++) s.insert(0);
    vector<pair<int,int>> a(n);
    for(auto &[l,r]:a) cin >> l >> r;
    sort(all(a),[](auto a,auto b){
            if(a.s != b.s) return a.s < b.s;
            return a.f < b.f;
    });
    int cnt = 0;
    for(auto [l,r]:a){
        auto it = s.upper_bound(l);
        if(it != s.begin()){
            s.erase(--it);
            cnt++;
            s.insert(r);
        }
    }
    cout << cnt;
    return 0;
}

