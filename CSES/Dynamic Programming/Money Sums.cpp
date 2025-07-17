#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) begin(x),end(x)
#define sz(x) (int)x.size()
#define ul unsigned long long

int gcd(int a,int b) {return b == 0 ? a:gcd(b,a%b);}

const int MAXN = 2e5;
int dp[MAXN + 10];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    vector<int> a(n);
    for(auto &e:a) cin >> e;

    vector<int> ans;
    dp[0] = 1;
    for(int i=0;i<n;i++){
        for(int j = MAXN;j >= 1;j--){
            if(j - a[i] < 0) continue;
            if(dp[j - a[i]] == 1) dp[j] = 1;
        }
    }
    for(int i=1;i<=MAXN;i++){
        if(dp[i]) ans.push_back(i);
    }

    cout << sz(ans) << '\n';
    for(auto &e:ans) cout << e << ' ';
}
