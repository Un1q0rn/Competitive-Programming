#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long int
#define pi pair<int,int>
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

struct cmp{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.first < b.first || (a.first == b.first && a.second < b.second);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    set<pair<int, int>, cmp> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert({x, i});
    }

    int lst = -1, p = 1e6, cnt = 0;
    while (sz(s)) {
        auto it = s.lower_bound({lst, p});
        if(it != s.end() && it->first == lst && it->second >= p){
            p = it->second;
            s.erase(it);
            lst--;
        } 
        else{
            lst = s.rbegin()->first;
            p = s.rbegin()->second;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
