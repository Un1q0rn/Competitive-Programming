#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) begin(x),end(x)
#define sz(x) (int)x.size()
#define ul unsigned long long

int gcd(int a,int b) {return b == 0 ? a:gcd(b,a%b);}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n;cin >> n;
    ll cnt = 0;
    set<int> s;
    vector<int> depth(n + 1);
    for(int i=0;i<n;i++){
        int x;cin >> x;
        if(i == 0){
            s.insert(x);
            depth[x] = 0;
            cout << 0 << '\n';
            continue;
        }
        auto L = s.lower_bound(x);
        auto R = s.upper_bound(x);
        depth[x] = max((L == s.begin() ? -1 : depth[*(--L)]),(R == s.end() ? -1 : depth[*R])) + 1;
        s.insert(x);
        cnt += depth[x];
        cout << cnt << '\n';
    }
    return 0;
}
