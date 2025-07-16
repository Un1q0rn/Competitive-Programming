#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 2e3;

ll dp[MAXN + 10][MAXN + 10];
void binomial() {
	for(int i = 0; i <= MAXN; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || i == j){
                dp[i][j] = 1;
            }
            else{
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]);
			}
		}
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    binomial();
    int n,k;cin >> n >> k;
    cout << dp[n][k];
}
