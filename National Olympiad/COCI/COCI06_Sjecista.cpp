#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long int
#define pi pair<int,int>
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    int ans = 0;
    for(int i=2;i<n-1;i++){
        ans += (i-1) * (n-i-1);
    }
    ans *= n;
    ans >>= 2;
    cout << ans;
    return 0;
}
