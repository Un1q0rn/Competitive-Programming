#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define ll long long
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
double dp[50][50][50][50][2];
bool vis[50][50][50][50][2];

double calc(double rr, double rb, double br, double bb) {
    double maximin = max(min(rr, rb), min(br, bb));
    double minimax = min(max(rr, br), max(rb, bb));

    if (abs(maximin - minimax) < 1e-9) {
        return maximin;
    }

    double deno = (rr + bb) - (rb + br);
    
    if (abs(deno) < 1e-9) {
        return maximin; 
    }

    return (rr * bb - rb * br) / deno;
}

double P(int r1,int b1,int r2,int b2,int t){
    if(r1 <= 0 || b1 <= 0){
        return 0.0;
    }
    if(r2 <= 0 || b2 <= 0){
        return 1.0;
    }

    if(vis[r1][b1][r2][b2][t]){
        return dp[r1][b1][r2][b2][t];
    }

    double rr, rb, br, bb;
    vis[r1][b1][r2][b2][t] = true;

    if (t == 0) {
        rr = P(r1 - 1, b1, r2, b2, t ^ 1);
        rb = P(r1, b1, r2, b2 - 1, t ^ 1);
        br = P(r1, b1, r2 - 1, b2, t ^ 1);
        bb = P(r1, b1 - 1, r2, b2, t ^ 1);
    } else {
        rr = P(r1, b1, r2 - 1, b2, t ^ 1); 
        rb = P(r1, b1 - 1, r2, b2, t ^ 1);
        br = P(r1 - 1, b1, r2, b2, t ^ 1);
        bb = P(r1, b1, r2, b2 - 1, t ^ 1);
    }

    return dp[r1][b1][r2][b2][t] = calc(rr, rb, br, bb);
}

void solve() {
    int r1,b1,r2,b2;
    cin >> r1 >> b1 >> r2 >> b2;

    P(r1,b1,r2,b2,0);

    cout << dp[r1][b1][r2][b2][0];
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
